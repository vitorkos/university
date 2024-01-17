/*Este trecho é um cabeçalho de guarda típico utilizado em arquivos de cabeçalho (.h) em C. Ele evita que o conteúdo do arquivo seja incluído mais de uma vez no mesmo código-fonte, prevenindo erros de compilação relacionados à redefinição de símbolos.*/

#ifndef ZMDP_SRC_PARSERS_DECISION_TREE_H_
#define ZMDP_SRC_PARSERS_DECISION_TREE_H_

/* Inicializa a biblioteca de árvores de decisão - a dimensionalidade do modelo
   deve ser especificada para que as tabelas na árvore de decisão possam ser
   alocadas adequadamente posteriormente. */
extern void dtInit(int numActions, int numStates, int numObservations);

/* Adiciona uma entrada à árvore de decisão. Qualquer um dos quatro primeiros argumentos
   pode receber o valor -1 (== WILDCARD_SPEC), indicando um caractere curinga.
   Chamadas posteriores para dtAdd() sobrescrevem chamadas anteriores. */
extern void dtAdd(int action, int cur_state, int next_state, int obs,
                  double val);

/* Retorna a recompensa imediata para uma tupla específica [a, s, s', o]. */
extern double dtGet(int action, int cur_state, int next_state, int obs);

/* Limpa todas as estruturas de dados da árvore de decisão no heap. */
extern void dtDeallocate(void);

/* Imprime uma representação textual da estrutura de dados da árvore de decisão em
   stdout. Destinado a fins de depuração. */
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

//Parâmetros e constantes da árvore de decisão

/*
Essas definições representam constantes importantes para o funcionamento da
árvore de decisão. DT_TABLE_DEPTH indica a profundidade da tabela da árvore,
enquanto WILDCARD_SPEC_FLOAT é utilizado como um valor especial para
representar um caractere curinga (wildcard) quando os dados da árvore
envolvem valores de ponto flutuante.
*/
#define DT_TABLE_DEPTH (4)
//#define WILDCARD_SPEC (-1) /* redundant definition with imm-reward.h */
#define WILDCARD_SPEC_FLOAT (-1.0)


//Enumeração para tipos de nós na árvore de decisão

/*
Essa enumeração define dois valores possíveis para o tipo de nó na árvore de
decisão: DT_VAL, representando um nó de valor, e DT_TABLE, representando um
nó de tabela.
*/

enum
{
    DT_VAL, // Nó de valor
    DT_TABLE // Nó de tabela
};

/************************
 * DATA STRUCTURES
 ************************/

// Alteração no tipo usado para representar valores curinga
typedef float wildcard_t;

//Definições antecipadas das estruturas de nós e tabelas na árvore de decisão.

/*
Estas linhas fornecem declarações avançadas (forward declarations) para as
estruturas de nó (DTNodeStruct) e tabela (DTTableStruct) usadas na
implementação da árvore de decisão.
*/

struct DTNodeStruct;
struct DTTableStruct;

// Estrutura de Tabela para a Árvore de Decisão.

/*
Esta estrutura representa uma tabela na árvore de decisão. Ela armazena o
número de entradas, um ponteiro para as entradas (nodes) e uma entrada padrão
(defaultEntry).
*/

struct DTTableStruct
{
    int numEntries; // Número de entradas na tabela
    struct DTNodeStruct **entries; // Ponteiro para as entradas da tabela
    struct DTNodeStruct *defaultEntry; // Entrada padrão (usada quando uma entrada específica não está definida)
};

// Estrutura de Nó para a Árvore de Decisão.

/*
Esta estrutura representa um nó na árvore de decisão. Cada nó pode ser de
dois tipos: DT_VAL (valor) ou DT_TABLE (tabela).
*/

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

// Variáveis Globais para Tamanhos de Tabela e Raiz da Árvore de Decisão.

/*
Essas variáveis globais mantêm informações cruciais para o funcionamento da
árvore de decisão, como os tamanhos das tabelas e a raiz da árvore.
*/

static int *gTableSizes = NULL; // Tamanhos das tabelas
static DTNode *gTree = NULL; // Raiz da árvore de decisão

/************************
 * INTERNAL HELPER FUNCTIONS
 ************************/


//Cria um Novo Nó com Valor.

/* Esta função cria um novo nó do tipo valor (DT_VAL) e atribui o valor fornecido
a ele.

@param val O valor a ser atribuído ao nó.
@return Um ponteiro para o novo nó criado.
*/

static DTNode *dtNewNodeVal(double val)
{
    DTNode *out;

    out = (DTNode *)malloc(sizeof(DTNode));
    out->type = DT_VAL;
    out->data.val = val;

    return out;
}


// Criação de Novo Nó com Tabela.

/*
Esta função cria um novo nó do tipo tabela com o número especificado de entradas
e retorna o ponteiro para esse novo nó.

@param numEntries: Número de entradas na tabela.
@return: Ponteiro para o novo nó de tabela.
*/

static DTNode *dtNewNodeTable(int numEntries)
{
    DTNode *out;

    out = (DTNode *)malloc(sizeof(DTNode));
    out->type = DT_TABLE;
    dtInitTable(&out->data.subTree, numEntries);

    return out;
}

// Inicialização de Tabela.

/*
Esta função inicializa uma tabela com o número especificado de entradas.

@param t: Ponteiro para a tabela a ser inicializada.
@param numEntries: Número de entradas na tabela.
*/

static void dtInitTable(DTTable *t, int numEntries)
{
    t->numEntries = numEntries;
    t->entries = (DTNode **)malloc(numEntries * sizeof(DTNode *));
    memset(t->entries, 0, numEntries * sizeof(DTNode *));
    t->defaultEntry = NULL; /* will be allocated later */
}


// Destruição de Nó.

/*
Esta função libera a memória alocada para um nó da árvore de decisão e
recursivamente destrói os nós filhos, se houver.

@param n: Ponteiro para o nó a ser destruído.
*/

static void dtDestroyNode(DTNode *n)
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

// Destruição de Tabela.

/*
Esta função libera a memória alocada para uma tabela na árvore de decisão,
incluindo a destruição dos nós filhos e a lista de entradas.

@param t: Ponteiro para a tabela a ser destruída.
*/

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

// Cópia Profunda de Nó.

/*
Esta função realiza uma cópia profunda de um nó da árvore de decisão, incluindo
cópias de todos os nós filhos.

@param in: Ponteiro para o nó a ser copiado.
@return Ponteiro para a cópia profunda do nó.
*/

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

// Cópia Profunda de Tabela.

/*
Esta função realiza uma cópia profunda de uma tabela da árvore de decisão,
incluindo cópias de todos os nós filhos.

@param out: Ponteiro para a tabela de destino.
@param in: Ponteiro para a tabela de origem.
 */

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

// Converte Nó para Tabela.

/*
Esta função converte um nó para uma tabela, criando uma nova tabela e
movendo o valor do nó original para a entrada padrão da nova tabela.
O nó original é destruído no processo.

@param in: Ponteiro para o nó de origem.
@param numEntries: Número de entradas na nova tabela.
@return Ponteiro para o novo nó (que agora é uma tabela).
*/

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

// Adiciona Internamente à Árvore de Decisão.

/*
Esta função adiciona um valor apropriado à árvore de decisão internamente.
Avalia elementos de um vetor de wildcards para determinar a ação apropriada.

@param node: Ponteiro para o nó da árvore.
@param vec: Vetor de wildcards.
@param index: Índice atual no vetor.
@param val: Valor a ser adicionado.
@return Ponteiro para o nó modificado.
*/
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

// Obtém Internamente da Árvore de Decisão.

/*
Esta função obtém o valor imediato para um determinado [a, s, s', o] tuple.
Avalia elementos de um vetor de wildcards para determinar a ação apropriada.

@param node: Ponteiro para o nó da árvore.
@param vec: Vetor de wildcards.
@param index: Índice atual no vetor.
@return Valor obtido.
*/

static double dtGetInternal(DTNode *node, wildcard_t *vec, int index)
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

// Imprime Espaços para Fins de Debugging.

static void dtSpaces(int indent)
{
    int i;

    for (i = 0; i < indent; i++)
    {
        putchar(' ');
    }
}

// Imprime um Nó da Árvore de Decisão para Fins de Debugging.

/*
Esta função imprime um nó da árvore de decisão para fins de depuração, incluindo
informações sobre o tipo do nó (VAL ou TABLE) e seu valor ou subárvore.

@param n: Ponteiro para o nó a ser impresso.
@param indent: Número de espaços para indentação.
*/

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

// Imprime uma Tabela da Árvore de Decisão para Fins de Debugging.

/*
Esta função imprime uma tabela da árvore de decisão para fins de depuração, incluindo
informações sobre a entrada padrão e as entradas específicas.

@param t: Ponteiro para a tabela a ser impressa.
@param indent: Número de espaços para indentação.
*/

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

// Inicializa a Árvore de Decisão.

/*
Esta função inicializa a árvore de decisão com as dimensões especificadas.

@param numActions: Número de ações possíveis.
@param numStates: Número de estados possíveis.
@param numObservations: Número de observações possíveis.
*/

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

// Adiciona uma entrada à Árvore de Decisão.

/*
Esta função adiciona uma entrada à árvore de decisão com os parâmetros especificados.

@param action: Ação associada à entrada.
@param cur_state: Estado atual associado à entrada.
@param next_state: Próximo estado associado à entrada.
@param obs: Observação associada à entrada.
@param val: Valor associado à entrada.
*/

void dtAdd(int action, int cur_state, int next_state, int obs, double val)
{
    int vec[DT_TABLE_DEPTH];
    vec[0] = action;
    vec[1] = cur_state;
    vec[2] = next_state;
    vec[3] = obs;

    gTree = dtAddInternal(gTree, vec, 0, val);
}

// Obtém o valor associado a uma entrada na Árvore de Decisão.

/*
Esta função retorna o valor associado a uma entrada específica na árvore de decisão,
com os parâmetros fornecidos.

@param action: Ação associada à entrada.
@param cur_state: Estado atual associado à entrada.
@param next_state: Próximo estado associado à entrada.
@param obs: Observação associada à entrada.
@return: Valor associado à entrada na árvore de decisão.
*/

double dtGet(int action, int cur_state, int next_state, int obs)
{
    int vec[DT_TABLE_DEPTH];
    vec[0] = action;
    vec[1] = cur_state;
    vec[2] = next_state;
    vec[3] = obs;

    return dtGetInternal(gTree, vec, 0);
}

// Desaloca os recursos associados à Árvore de Decisão.

/*
Esta função libera toda a memória alocada para a estrutura da árvore de decisão e
reinicializa as variáveis globais para evitar vazamentos de memória.
*/

void dtDeallocate(void)
{
    dtDestroyNode(gTree);
    gTree = NULL;
    free(gTableSizes);
    gTableSizes = NULL;
}

// Imprime uma representação textual da Árvore de Decisão para depuração.

/*
@param header Um cabeçalho opcional para a saída.

Esta função imprime uma representação textual da estrutura da Árvore de Decisão,
incluindo valores nos nós e entradas nas tabelas, para auxiliar na depuração do código.
*/

void dtDebugPrint(const char *header)
{
    printf("%s\n", header);
    dtDebugPrintNode(gTree, 2);
}

/************************
 * TEST SECTION
 ************************/

// Realiza um teste único para construção, consulta e destruição da Árvore de Decisão.

/*
Esta função lê dados do arquivo "treino.txt" e realiza operações básicas, como inicialização
da árvore, adição de entradas e consultas. Ela é usada para testar a funcionalidade do código.

@return Retorna 0 se o teste for concluído com sucesso, caso contrário, retorna 1.
*/

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

int main(int argc, char **argv)
{
    // testOnce();
    testOnce();
    return 0;
}