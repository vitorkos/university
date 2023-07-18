#include <stdio.h>;
#include <stdlib.h>;

struct produto{
    char nome[20];
    int codigo;
    float valor;
    int data[3];
};

struct lista{
    struct produto produto;
    struct lista *prox;
};

typedef struct lista Lista;
typedef struct produto Produto;
