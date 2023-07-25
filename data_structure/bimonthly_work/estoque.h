#include <stdio.h>;
#include <stdlib.h>;

struct produto{
    char nome[20];
    int codigo;
    float valor;
    int data[3];
};

struct lista{
    struct produto *produto;
    struct lista *prox;
};

typedef struct lista Lista;
typedef struct produto Produto;


/* Cria um novo produto */
Produto * CriaProduto ( char * nome , int codigo , float valor , int*data_de_validade ) ;

Lista * CriaLista () ;

/* Insere um produto em uma lista */
Lista * InsereListaProduto ( Lista * l , Produto * p ) ;

/* Retira um produto de uma determinada lista */
Lista * RetiraListaProduto ( Lista * l , int id_produto ) ;

/* Verifica se um produto e s t presente em uma determinada lista */
int VerificaListaProduto ( Lista * p , int id_produto ) ;

/* Verifica se existe um produto e s t vencido em uma determinadalista */
Lista * VerificaListaValidade ( Lista * p, int d, int m, int a) ;

/* Imprime todos os produtos de uma lista */
void ImprimeListaProdutos ( Lista * p ) ;

/* Orderna Lista pelo valor do produto */
Lista * OrdenaListaValor ( Lista * p ) ;

/* Orderna Lista pelo valor do produto */
Lista * OrdenaListaVencimento ( Lista * p ) ;