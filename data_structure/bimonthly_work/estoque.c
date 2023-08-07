#include "estoque.h"

struct produto{
    char nome[20];
    int codigo;
    float valor;
    int data[3];

};

struct lista {
    Produto *produto;
    Lista *prox;
};

//FUNÇÕES DE MANIPULAÇÃO DE LISTA

//Cria uma lista vazia
Lista *CriaLista(){
    return NULL;
}

//Criar um produto novo
Produto *CriaProduto(char *nome, int codigo, float valor, int *data){
    Produto *p = (Produto*) malloc(sizeof(Produto));

    //Verifica se a alocação foi bem sucedida
    if (p == NULL){
        puts("Fala ao criar o produto!"\n");
        perror(NULL);
    }

    //Copia os dados para o produto
    p->codigo = codigo;
    p->valor = valor;
    for (int i = 0; i < sizeof(p->nome); i++) {
        if (i < 3) {
            p->data[i] = *(data_de_validade + i);
        }

        p->nome[i] = *(nome + i);
    }

    return p;
}

//Insere um produto na lista
Lista *InsereListaProduto(Lista *l, Produto *p){
    Lista *novo = (Lista*) malloc(sizeof(Lista));

    fseek(arquivo_final, 0, SEEK_END);

    //Verifica se a alocação foi bem sucedida
    if (novo == NULL){
        puts("Falha ao inserir o produto!"\n");
        perror(NULL);
    }

    //Insere o produto na lista
    novo->produto = p;
    novo->prox = l;

    fprintf(arquivo_final, "PRODUTO %s %d ADICIONADO\n", p->nome, p->codigo);

    return novo;
}

//Remove um produto da lista
Lista *RetiraListaProduto(Lista *l, int codigo){
    Lista *ant = CriaLista();
    Lista *p = l;

    fseek(arquivo_final, 0, SEEK_END);

    //Procura o produto na lista
    while (p != NULL && p->produto->codigo != codigo){
        ant = p;
        p = p->prox;
    }

    //Verifica se o produto foi encontrado
    if (p == NULL){
        fprintf(arquivo_final, "PRODUTO %d NAO ENCONTRADO\n", codigo);
        return l;
    }

    //Remove o produto da lista
    if (ant == NULL){
        //Elemento a ser removido é o primeiro da lista
        l = p->prox;
    } else {
        //Elemento a ser removido não é o primeiro da lista
        ant->prox = p->prox;
    }

    fprintf(arquivo_final, "PRODUTO %s %d REMOVIDO\n", p->produto->nome, p->produto->codigo);

    free(p->produto);
    free(p);

    return l;
}

//Verifica se um produto está na lista
int VerificaListaProduto(Lista *l, int codigo){
    Lista *p = l;

    //Procura o produto na lista
    while (p != NULL && p->produto->codigo != codigo){
        p = p->prox;
    }

    //Verifica se o produto foi encontrado
    if (p == NULL){
        return 0;
    }

    return 1;
}

//Atualiza o preço de um produto
Lista *AtualizaPrecoProduto(Lista *l, int codigo, float valor){
    Lista *p = l;

    //Procura o produto na lista
    while (p != NULL && p->produto->codigo != codigo){
        p = p->prox;
    }

    //Verifica se o produto foi encontrado
    if (p == NULL){
        fprintf(arquivo_final, "PRODUTO %d NAO ENCONTRADO\n", codigo);
        return l;
    }

    //Atualiza o preço do produto
    p->produto->valor = valor;

    fprintf(arquivo_final, "PRODUTO %s %d PRECO ATUALIZADO PARA %.2f\n", p->produto->nome, p->produto->codigo, p->produto->valor);

    return l;
}

//Verifica se um produto está vencido
int VerificaListaValidade(Lista *l, int dia, int mes, int ano){
    Lista *p = l;

    //Procura o produto na lista
    while (p != NULL && p->produto->codigo != codigo){
        p = p->prox;
    }

    //Verifica se o produto foi encontrado
    if (p == NULL){
        return 0;
    }

    //Verifica se o produto está vencido
    if (p->produto->data[2] < ano){
        return 1;
    } else if (p->produto->data[2] == ano){
        if (p->produto->data[1] < mes){
            return 1;
        } else if (p->produto->data[1] == mes){
            if (p->produto->data[0] < dia){
                return 1;
            }
        }
    }

    return 0;
}

//Imprime a lista de produtos
void ImprimeListaProdutos(Lista *l){
    Lista *p = l;

    //Verifica se a lista está vazia
    if (p == NULL){
        fprintf(arquivo_final, "LISTA VAZIA\n");
        return;
    }

    //Imprime a lista
    fprintf(arquivo_final, "LISTA DE PRODUTOS:\n");
    while (p != NULL){
        fprintf(arquivo_final, "%s %d %.2f %d/%d/%d\n", p->produto->nome, p->produto->codigo, p->produto->valor, p->produto->data[0], p->produto->data[1], p->produto->data[2]);
        p = p->prox;
    }
}

//Ordena a lista de produtos pelo valor do produto
Lista *OrdenaListaValor(Lista *l){
    Lista *p;

    if(l == NULL){
        return l;
    }

    for(p = l; p->prox != NULL; p = p->prox){
        Lista *menor = p;
        Lista *q;

        for(q = p->prox; q != NULL; q = q->prox){
            if(q->produto->valor < menor->produto->valor){
                menor = q;
            }
        }

        if(menor != p){
            Produto *aux = p->produto;
            p->produto = menor->produto;
            menor->produto = aux;
        }
    }

    return l;
}

//Ordena a lista de produtos pela data de validade do produto
Lista *OrdenaListaVencimento(Lista *l){
    Lista *p;

    if(l == NULL){
        return l;
    }

    for(p = l; p->prox != NULL; p = p->prox){
        Lista *menor = p;
        Lista *q;

        for(q = p->prox; q != NULL; q = q->prox){
            if(q->produto->data[2] < menor->produto->data[2]){
                menor = q;
            } else if (q->produto->data[2] == menor->produto->data[2]){
                if(q->produto->data[1] < menor->produto->data[1]){
                    menor = q;
                } else if (q->produto->data[1] == menor->produto->data[1]){
                    if(q->produto->data[0] < menor->produto->data[0]){
                        menor = q;
                    }
                }
            }
        }

        if(menor != p){
            Produto *aux = p->produto;
            p->produto = menor->produto;
            menor->produto = aux;
        }
    }

    return l;
}