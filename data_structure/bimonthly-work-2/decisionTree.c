#ifndef ZMDP_SRC_PARSERS_DECISION_TREE_H_
#define ZMDP_SRC_PARSERS_DECISION_TREE_H_

/* Initialize the decision-tree library--dimensionality of the model
   must be specified so that tables in the decision tree can be
   allocated appropriately later. */
extern void dtInit(int numActions, int numStates, int numObservations);

/* Adds an entry to the decision tree.  Any of the first four arguments
   can be given the value -1 (== WILDCARD_SPEC), indicating a wildcard.
   Later calls to dtAdd() overwrite earlier calls. */
extern void dtAdd(int action, int cur_state, int next_state, int obs,
                  double val);

/* Returns the immediate reward for a particular [a,s,s',o] tuple. */
extern double dtGet(int action, int cur_state, int next_state, int obs);

/* Cleans up all decision tree data structures on the heap. */
extern void dtDeallocate(void);

/* Print a textual representation of the decision tree data structure to
   stdout.  Intended for debugging. */
extern void dtDebugPrint(const char *header);

#endif // ZMDP_SRC_PARSERS_DECISION_TREE_H_

// #include "tree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************
 * MACROS
 ************************/

#define DT_TABLE_DEPTH (4)
#define WILDCARD_SPEC (-1) /* redundant definition with imm-reward.h */

enum
{
    DT_VAL,
    DT_TABLE
};

/************************
 * DATA STRUCTURES
 ************************/

struct DTNodeStruct;
struct DTTableStruct;

struct DTTableStruct
{
    int numEntries;
    struct DTNodeStruct **entries;
    struct DTNodeStruct *defaultEntry;
};

struct DTNodeStruct
{
    int type;
    union
    {
        struct DTTableStruct subTree;
        double val;
    } data;
};

typedef struct DTNodeStruct DTNode;
typedef struct DTTableStruct DTTable;

/************************
 * FUNCTION PROTOTYPES
 ************************/

static DTNode *dtNewNodeVal(double val);
static DTNode *dtNewNodeTable(int numEntries);
static void dtInitTable(DTTable *t, int numEntries);
static void dtDestroyNode(DTNode *n);
static void dtDestroyTable(DTTable *t);
static DTNode *dtDeepCopyNode(const DTNode *in);
static void dtDeepCopyTable(DTTable *out, const DTTable *in);
static DTNode *dtConvertToTable(DTNode *in, int numEntries);
static void dtSpaces(int indent);
static void dtDebugPrintNode(DTNode *n, int indent);
static void dtDebugPrintTable(DTTable *t, int indent);

/************************
 * GLOBAL VARIABLES
 ************************/

static int *gTableSizes = NULL;
static DTNode *gTree = NULL;

/************************
 * INTERNAL HELPER FUNCTIONS
 ************************/

static DTNode *dtNewNodeVal(double val)
{
    DTNode *out;

    out = (DTNode *)malloc(sizeof(DTNode));
    out->type = DT_VAL;
    out->data.val = val;

    return out;
}

static DTNode *dtNewNodeTable(int numEntries)
{
    DTNode *out;

    out = (DTNode *)malloc(sizeof(DTNode));
    out->type = DT_TABLE;
    dtInitTable(&out->data.subTree, numEntries);

    return out;
}

static void dtInitTable(DTTable *t, int numEntries)
{
    t->numEntries = numEntries;
    t->entries = (DTNode **)malloc(numEntries * sizeof(DTNode *));
    memset(t->entries, 0, numEntries * sizeof(DTNode *));
    t->defaultEntry = NULL; /* will be allocated later */
}

static void dtDestroyNode(DTNode *n)
{
    if (NULL == n)
        return;

    switch (n->type)
    {
    case DT_VAL:
        /* nothing to do */
        break;
    case DT_TABLE:
        dtDestroyTable(&n->data.subTree);
        break;
    default:
        assert(0 /* never reach this point */);
    }

    free(n);
}

static void dtDestroyTable(DTTable *t)
{
    int i;

    for (i = 0; i < t->numEntries; i++)
    {
        dtDestroyNode(t->entries[i]);
    }
    dtDestroyNode(t->defaultEntry);
    free(t->entries);
    t->entries = NULL;
}

static DTNode *dtDeepCopyNode(const DTNode *in)
{
    DTNode *out;

    if (NULL == in)
    {
        out = NULL;
    }
    else
    {
        switch (in->type)
        {
        case DT_VAL:
            out = dtNewNodeVal(in->data.val);
            break;
        case DT_TABLE:
            out = dtNewNodeTable(in->data.subTree.numEntries);
            dtDeepCopyTable(&out->data.subTree, &in->data.subTree);
            break;
        default:
            assert(0 /* never reach this point */);
        }
    }

    return out;
}

static void dtDeepCopyTable(DTTable *out, const DTTable *in)
{
    int i;

    dtInitTable(out, in->numEntries);
    out->defaultEntry = dtDeepCopyNode(in->defaultEntry);
    for (i = 0; i < in->numEntries; i++)
    {
        if (NULL != in->entries[i])
        {
            out->entries[i] = dtDeepCopyNode(in->entries[i]);
        }
    }
}

static DTNode *dtConvertToTable(DTNode *in, int numEntries)
{
    DTNode *out;

    assert(NULL != in);

    switch (in->type)
    {
    case DT_VAL:
        out = dtNewNodeTable(numEntries);
        out->data.subTree.defaultEntry = dtNewNodeVal(in->data.val);
        dtDestroyNode(in);
        break;
    case DT_TABLE:
        out = in;
        break;
    default:
        assert(0 /* never reach this point */);
    }

    return out;
}

DTNode *dtAddInternal(DTNode *node, int *vec, int index, double val)
{
    int i;
    int allWildcards;
    DTNode **entryP;

    /* set allWildcards to be true if all remaining elements of vec are
       wildcards.  (allWildcards is vacuously true if index >=
       DT_TABLE_DEPTH). */
    allWildcards = 1;
    for (i = index; i < DT_TABLE_DEPTH; i++)
    {
        if (vec[i] != WILDCARD_SPEC)
        {
            allWildcards = 0;
            break;
        }
    }

    if (allWildcards)
    {
        /* all remaining vec elements are wildcards... nuke whatever node
           was present before and replace it with a VAL node */
        dtDestroyNode(node);
        node = dtNewNodeVal(val);
    }
    else if (WILDCARD_SPEC == vec[index])
    {
        /* this vec element is a wildcard but not all the rest are... make
           sure the node is a table and addInternal to both defaultEntry and
           all non-NULL entries in the table */
        node = dtConvertToTable(node, gTableSizes[index]);
        node->data.subTree.defaultEntry =
            dtAddInternal(node->data.subTree.defaultEntry, vec, index + 1, val);
        for (i = 0; i < gTableSizes[index]; i++)
        {
            if (NULL != node->data.subTree.entries[i])
            {
                node->data.subTree.entries[i] =
                    dtAddInternal(node->data.subTree.entries[i], vec, index + 1, val);
            }
        }
    }
    else
    {
        /* this element of vec is not a wildcard... make sure the node is a
           table and modify just the appropriate entry */
        node = dtConvertToTable(node, gTableSizes[index]);
        entryP = &node->data.subTree.entries[vec[index]];
        if (NULL == *entryP)
        {
            /* the given entry is not set at all yet.. first copy the default before
               making modifications */
            *entryP = dtDeepCopyNode(node->data.subTree.defaultEntry);
        }
        *entryP = dtAddInternal(*entryP, vec, index + 1, val);
    }

    return node;
}

static double dtGetInternal(DTNode *node, int *vec, int index)
{
    DTNode *entry;

    assert(NULL != node);

    switch (node->type)
    {
    case DT_VAL:
        return node->data.val;
    case DT_TABLE:
        entry = node->data.subTree.entries[vec[index]];
        if (NULL == entry)
        {
            entry = node->data.subTree.defaultEntry;
        }
        return dtGetInternal(entry, vec, index + 1);
    default:
        assert(0 /* never reach this point */);
    }
}

static void dtSpaces(int indent)
{
    int i;

    for (i = 0; i < indent; i++)
    {
        putchar(' ');
    }
}

static void dtDebugPrintNode(DTNode *n, int indent)
{
    if (NULL == n)
    {
        dtSpaces(indent);
        printf("(NULL)\n");
        return;
    }

    switch (n->type)
    {
    case DT_VAL:
        dtSpaces(indent);
        printf("val = %lf\n", n->data.val);
        break;
    case DT_TABLE:
        dtDebugPrintTable(&n->data.subTree, indent);
        break;
    default:
        assert(0 /* never reach this point */);
    }
}

static void dtDebugPrintTable(DTTable *t, int indent)
{
    int i;

    dtSpaces(indent);
    printf("table:\n");
    dtSpaces(indent + 2);
    printf("default:\n");
    dtDebugPrintNode(t->defaultEntry, indent + 4);
    for (i = 0; i < t->numEntries; i++)
    {
        dtSpaces(indent + 2);
        if (NULL == t->entries[i])
        {
            printf("entry %d: (default)\n", i);
        }
        else
        {
            printf("entry %d:\n", i);
            dtDebugPrintNode(t->entries[i], indent + 4);
        }
    }
}

/************************
 * EXPORTED FUNCTIONS
 ************************/

void dtInit(int numActions, int numStates, int numObservations)
{
    /* guard to prevent double initialization */
    if (NULL != gTree)
        return;

    gTableSizes = (int *)malloc(DT_TABLE_DEPTH * sizeof(int));
    gTableSizes[0] = numActions;
    gTableSizes[1] = numStates;
    gTableSizes[2] = numStates;
    gTableSizes[3] = numObservations;

    gTree = dtNewNodeVal(0);
}

void dtAdd(int action, int cur_state, int next_state, int obs, double val)
{
    int vec[DT_TABLE_DEPTH];
    vec[0] = action;
    vec[1] = cur_state;
    vec[2] = next_state;
    vec[3] = obs;

    gTree = dtAddInternal(gTree, vec, 0, val);
}

double dtGet(int action, int cur_state, int next_state, int obs)
{
    int vec[DT_TABLE_DEPTH];
    vec[0] = action;
    vec[1] = cur_state;
    vec[2] = next_state;
    vec[3] = obs;

    return dtGetInternal(gTree, vec, 0);
}

void dtDeallocate(void)
{
    dtDestroyNode(gTree);
    gTree = NULL;
    free(gTableSizes);
    gTableSizes = NULL;
}

void dtDebugPrint(const char *header)
{
    printf("%s\n", header);
    dtDebugPrintNode(gTree, 2);
}

/************************
 * TEST SECTION
 ************************/

int testOnce()
{
    FILE *file;
    file = fopen("treino.txt", "r"); // Change "input.txt" to the name of your file

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    int nActions, nStates, nObservations;
    float v1, v2, v3, v4, v5, result;

    // Read the first line
    fscanf(file, "%d %d %d", &nActions, &nStates, &nObservations);
    printf("%d %d %d\n", nActions, nStates, nObservations);
    //set up table
    dtInit(nActions, nStates, nObservations);
    // Read the following lines
    while (fscanf(file, "%f,%f,%f,%f,%f", &v1, &v2, &v3, &v4, &v5) != EOF)
    {
        printf("%.1f %.1f %.1f %.1f %.1f\n", v1, v2, v3, v4, v5);

        dtAdd((int)v1, (int)v2, (int)v3, (int)v4, v5);
        
        //do a few queries
        //result = dtGet((int)v1, (int)v2, (int)v3, (int)v4);
        //printf("expecting: result=%lf\n", v5);
        //printf("got:       result=%lf\n", result);


    }

    // clean up
    //dtDebugPrint("Before deallocate");
    dtDeallocate();
    //dtDebugPrint("After deallocate");

    fclose(file);

    return 0;
    /*
    double result;

    //set up table
    dtInit(5, 5, 5);

    dtAdd(0, 1, 2, 3, 0.5);
    dtAdd(0, 1, 2, 3, 0.7);

    dtAdd(0, 1, 3, -1, -10.1);
    dtAdd(0, 1, 3, -1, -10.3);

    dtAdd(1, 0, 0, -1, 6.0);
    dtAdd(1, 0, -1, -1, 7.0);

    dtAdd(-1, 2, -1, -1, 2.7);

    //do a few queries
    result = dtGet(0, 1, 2, 3);
    printf("expecting: result=%lf\n", 0.7);
    printf("got:       result=%lf\n", result);

    result = dtGet(0, 1, 3, 1);
    printf("expecting: result=%lf\n", -10.3);
    printf("got:       result=%lf\n", result);

    result = dtGet(1, 0, 0, 0);
    printf("expecting: result=%lf\n", 7.0);
    printf("got:       result=%lf\n", result);

    result = dtGet(3, 2, 0, 0);
    printf("expecting: result=%lf\n", 2.7);
    printf("got:       result=%lf\n", result);

    // clean up
    dtDeallocate();
    */
}

int main(int argc, char **argv)
{
    // testOnce();
    testOnce();
    return 0;
}