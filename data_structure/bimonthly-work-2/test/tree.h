// Functions headers

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tree.h

#ifndef TREE_H
#define TREE_H

typedef struct DTNodeStruct DTNode;
typedef struct DTTableStruct DTTable;

typedef float wildcard_t;

void dtInit(int numActions, int numStates, int numObservations);
void dtAdd(int action, int cur_state, int next_state, int obs, double val);
double dtGet(int action, int cur_state, int next_state, int obs);
void dtDeallocate(void);
DTNode *dtNewNodeVal(double val);
DTNode *dtNewNodeTable(int numEntries);
void dtInitTable(DTTable *t, int numEntries);
void dtDestroyNode(DTNode *n);
void dtDestroyTable(DTTable *t);
DTNode *dtDeepCopyNode(const DTNode *in);
void dtDeepCopyTable(DTTable *out, const DTTable *in);
DTNode *dtConvertToTable(DTNode *in, int numEntries);
void dtSpaces(int indent);
void dtDebugPrintNode(DTNode *n, int indent);
void dtDebugPrintTable(DTTable *t, int indent);
void dtDebugPrint(const char *header);

#endif // TREE_H
