#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"

//cria lista
Lista *CriaLista(){return NULL;}

Produto *CriaProduto ( char * nome , int codigo , float valor , int*data_de_validade ){
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    novoProduto->nome = nome;
    novoProduto->codigo = codigo;
    novoProduto->valor = valor;
    novoProduto->data = data_de_validade;

}


/* Insere um produto em uma lista */
Lista *InsereListaProduto ( Lista *l , Produto *p ){
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    novaLista->produto = p;
    novaLista->prox = l;
}



/* Retira um produto de uma determinada lista */
Lista * RetiraListaProduto ( Lista * l , int id_produto ){
    Lista *anterior = CriaLista();
    Lista *novaLista = l;

    while(novaLista != NULL && novaLista->produto != id_produto){
        anterior = novaLista;
        novaLista = novaLista->prox; 
    }
    if(novaLista == NULL){
        return l;
    }

    if(anterior == NULL){
        l = novaLista->prox;
    } else{
        anterior->prox = novaLista->prox;
    }
    free(novaLista);
    return l;
}


/* Verifica se um produto e s t presente em uma determinada lista */
int VerificaListaProduto ( Lista * p , int id_produto ){
    Lista *lista;
    for(lista = p; lista != NULL; lista = lista->prox){
        if(lista->produto->codigo == id_produto){
            return 1;
        }
    }
    return NULL;
}


/* Verifica se existe um produto e s t vencido em uma determinadalista */
Lista * VerificaListaValidade ( Lista * p, int d, int m, int a){
    Lista *lista;
    
    for(lista = p; lista != NULL; lista = lista->prox){
        if(lista->produto->data[2] < d){
            return p;
        }
        else if(lista->produto->data[1] < m){
            return p;
        }
        else if(lista->produto->data[0] < d){
            return p;
        }
        else{
            return 0;
        }
    }


}

/* Imprime todos os produtos de uma lista */
void ImprimeListaProdutos ( Lista * p ){

    Lista *lista ;
    for(lista = p; lista != NULL; lista = lista->prox){
        




    }
}




/* Orderna Lista pelo valor do produto */
Lista * OrdenaListaValor ( Lista * p ) ;

/* Orderna Lista pelo valor do produto */
Lista * OrdenaListaVencimento ( Lista * p ) ;