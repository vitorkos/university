// Functions implementations

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define DT_TABLE_DEPTH (4)
//#define WILDCARD_SPEC (-1) /* redundant definition with imm-reward.h */
#define WILDCARD_SPEC_FLOAT (-1.0)

enum
{
    DT_VAL, // Nó de valor
    DT_TABLE // Nó de tabela
};

typedef float wildcard_t;

struct DTNodeStruct;
struct DTTableStruct;

struct DTTableStruct
{
    int numEntries; // Número de entradas na tabela
    struct DTNodeStruct **entries; // Ponteiro para as entradas da tabela
    struct DTNodeStruct *defaultEntry; // Entrada padrão (usada quando uma entrada específica não está definida)
};

struct DTNodeStruct
{
    int type; // Tipo do nó: DT_VAL ou DT_TABLE
    union
    {
        struct DTTableStruct subTree; // Subárvore (usada quando o tipo é DT_TABLE)
        double val; // Valor associado (usado quando o tipo é DT_VAL)
    } data;
};

typedef struct DTNodeStruct DTNode;
typedef struct DTTableStruct DTTable;

static int *gTableSizes = NULL; // Tamanhos das tabelas
static DTNode *gTree = NULL; // Raiz da árvore de decisão

DTNode *dtNewNodeVal(double val)
{
    DTNode *out;

    out = (DTNode *)malloc(sizeof(DTNode));
    out->type = DT_VAL;
    out->data.val = val;

    return out;
}

DTNode *dtNewNodeTable(int numEntries)
{
    DTNode *out;

    out = (DTNode *)malloc(sizeof(DTNode));
    out->type = DT_TABLE;
    dtInitTable(&out->data.subTree, numEntries);

    return out;
}

void dtInitTable(DTTable *t, int numEntries)
{
    t->numEntries = numEntries;
    t->entries = (DTNode **)malloc(numEntries * sizeof(DTNode *));
    memset(t->entries, 0, numEntries * sizeof(DTNode *));
    t->defaultEntry = NULL; /* will be allocated later */
}

void dtDestroyNode(DTNode *n)
{
    if (NULL == n)
        return;

    switch (n->type)
    {
    case DT_VAL:
        /* Nada a fazer */
        break;
    case DT_TABLE:
        dtDestroyTable(&n->data.subTree);
        break;
    default:
        assert(0 /* Nunca atingirá este ponto */);
    }

    free(n);
}

void dtDestroyTable(DTTable *t)
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

DTNode *dtDeepCopyNode(const DTNode *in)
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

void dtDeepCopyTable(DTTable *out, const DTTable *in)
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

DTNode *dtConvertToTable(DTNode *in, int numEntries)
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

DTNode *dtAddInternal(DTNode *node, wildcard_t *vec, int index, double val)
{
    int i;
    int allWildcards;
    DTNode **entryP;

    /* Define allWildcards como verdadeiro se todos os elementos restantes de vec são
       wildcards. (allWildcards é vacuamente verdadeiro se index >=
       DT_TABLE_DEPTH). */
    allWildcards = 1;
    for (i = index; i < DT_TABLE_DEPTH; i++)
    {
        if (vec[i] != WILDCARD_SPEC_FLOAT)
        {
            allWildcards = 0;
            break;
        }
    }

    if (allWildcards)
    {
        /* todos os elementos restantes de vec são wildcards... destrói qualquer nó
           que estava presente antes e substitui por um nó VAL */
        dtDestroyNode(node);
        node = dtNewNodeVal(val);
    }
    else if (WILDCARD_SPEC_FLOAT == vec[index])
    {
        /* este elemento de vec é um wildcard, mas nem todos os outros são... garante
           que o nó seja uma tabela e adiciona internamente tanto para defaultEntry quanto
           para todas as entradas não nulas na tabela */
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
        /* este elemento de vec não é um wildcard... garante que o nó seja uma
           tabela e modifica apenas a entrada apropriada */
        node = dtConvertToTable(node, gTableSizes[index]);
        entryP = &node->data.subTree.entries[(int)vec[index]];
        if (NULL == *entryP)
        {
            /* a entrada dada ainda não está definida... primeiro copie o padrão antes de
               fazer modificações */
            *entryP = dtDeepCopyNode(node->data.subTree.defaultEntry);
        }
        *entryP = dtAddInternal(*entryP, vec, index + 1, val);
    }

    return node;
}

double dtGetInternal(DTNode *node, wildcard_t *vec, int index)
{
    DTNode *entry;

    assert(NULL != node);

    switch (node->type)
    {
    case DT_VAL:
        return node->data.val;
    case DT_TABLE:
        entry = node->data.subTree.entries[(int)vec[index]];
        if (NULL == entry)
        {
            entry = node->data.subTree.defaultEntry;
        }
        return dtGetInternal(entry, vec, index + 1);
    default:
        assert(0 /* never reach this point */);
    }
}

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
    while (fscanf(file, "%f,%f,%f,%f,%f", &v1, &v2, &v3, &v4, &v5) == 5)
    {
        printf("%.1f %.1f %.1f %.1f %.1f\n", v1, v2, v3, v4, v5);

        dtAdd(v1, v2, v3, v4, v5);
        // Do a few queries
        result = dtGet(v1, v2, v3, v4);
        printf("expecting: result=%lf\n", v5);
        printf("got:       result=%lf\n", result);
    }

    // clean up
    dtDeallocate();
    fclose(file);
    return 0;
}
