#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *f_arquivo;
//DEFININDO TYPEDEF PARA OS PRODUTOS E PARA A LISTA

//Tipo Produto
typedef struct produto Produto;

//Tipo Lista
typedef struct lista Lista;

//Cria lista vazia
Lista *CriaLista();

//Cria um produto
Produto *CriaProduto(char *nome, int codigo, float valor, int *data);

//Insere um produto na lista
Lista *InsereListaProduto(Lista *l, Produto *p);

//Retira um produto da lista
Lista *RetiraListaProduto(Lista *l, int codigo);

//Verifica se um produto está na lista
int VerificaListaProduto(Lista *l, int codigo);

//Verifica se um produto está vencido
int VerificaListaValidade(Lista *l, int dia, int mes, int ano);

//Atualiza o preço de um produto
Lista *AtualizaPrecoProduto(Lista *l, int codigo, float valor);

//Imprime a lista
void ImprimeListaProdutos(Lista *l);

//Ordena a lista
Lista *OrdenaListaValor(Lista *l);

//Ordena lisa vencimento
Lista *OrdenaListaVencimento(Lista *l);
