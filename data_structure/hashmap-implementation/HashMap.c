// incluindo bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNÇÕES DE HASHING( TRANSFORMAÇÃO DAS CHAVES )

//transformação de chaves numericas
//// h(k) = K % M; k = chave, M = tamanho do vetor de endereços

//transformação de chaves não numericas 
//cria um peso para cada caractere

/*vetor dos pesos*//*tamanho da chave*/ 
void geraPesos(int p[],int n){
    //utiliza o tempo como gerador dos valores aleatorios
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        // itera e cria um peso para cada caractere
        p[i] = 1 + (int) (10000.0 * rand() / RAND_MAX);
    }
}

//função de hashing ( retorna o indice daquela chave )
/*chave*/ /*vetor de pesos*/ /*tamanho do vetor*/ /*tamanho do vetor pesos*/ 
int h(char *chave, int p[], int m, int tam_p){
    unsigned int soma = 0;
    /*comprimento da chave*/
    int comp = strlen(chave);
    for(int i = 0; i < comp; i++){
        /*itera sob o comprimento da chave*/
        /*a cada iteração, incrementa a soma com (caractere i * resto de peso da posicao i / tamanho do vetor p)*/
        soma += (unsigned int) chave [i] * p[i % tam_p];
    }
    //retorna o resto da soma pelo tamanho do vetor de endereços
    return soma % m;
}

/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/


//RESOLVENDO COLISOES ( CHAVES COM O MESMO ENDEREÇO)

//TRATAMENTO DE COLISÕES USANDO LISTAS ENCADEADAS

#define N 16 //tamanho da chave ( string )

typedef char TChave[N];

//definicao de um item
typedef struct{
    /* outros componentes*/
    int matricula;
    float nota;
    TChave nome;
}TItem;

//definicao de uma celula de um lista encadeada
typedef struct celula{
    struct celula *pProx;
    TItem item;
}TCelula;

//definicao de uma lista encadeada na hash
typedef struct{
    TCelula *pPrimeiro, *pUltimo;
}TLista;

//definicao de uma tabela hash propriamente dita
typedef struct {
    int n; //numero de itens a serem armazenados na hash
    int nro_listas; //tamanho do array de listas
    int nro_pesos; //tamanho do array de pesos
    int *p; //vetor de pesos
    TLista *v; //array de listas
}THash;

//funcao de hashing que retorna o indice de uma chave
int THash_H(THash *hash, TChave chave){
    unsigned int soma = 0;
    int comp = strlen(chave);
    for(int i = 0; i < comp; i++){
        soma += (unsigned int)chave[i] * hash->p[i % hash->nro_pesos];
    }
    return (soma % hash->nro_listas);
}

//inicializa a tabela; p = numero de pesos; m = tamanho do vetor de listas
void THash_Inicia(THash *hash, int nro_listas, int nro_pesos){
    int i;
    hash->n = 0;
    hash->nro_listas = nro_listas;
    hash->nro_pesos = nro_pesos;

    //inicializando as listas
    hash->v = (TLista *)malloc(sizeof(TLista) * nro_listas);
    for(i = 0; i < nro_listas; i++){
        TLista_Inicia(&hash->v[i]);
    }

    //inicializando os pesos
    hash->p = (int *)malloc(sizeof(int) * nro_pesos);
    for(i = 0; i < nro_pesos; i++){
        hash->p[i] = rand() % 10000;
    }
}

//funções de pesquisa 1/2
//retorna o ponteiro para a celula
TCelula *THash_PesquisaCelula(THash *hash, TChave chave){
    int i = THash_H(hash, chave);
    TCelula *aux;

    if(TLista_EhVazia(&hash->v[i])) return NULL;

    aux = hash->v[i].pPrimeiro;

    while(aux->pProx->pProx != NULL &&
          strcmp(chave, aux->pProx->item.nome) != 0);
        aux = aux->pProx;

    if(!strncmp(chave, aux->pProx->item.nome, sizeof(TChave)))
        return aux;
    else return NULL;
}

//funções de pesquisa 2/2
//retorna se a pesquisa foi bem sucedida e o item x por referencia
int THash_Pesquisa(THash *hash, TChave chave, TItem *x){
    TCelula *aux = THash_PesquisaCelula(hash, chave);
    if(aux == NULL) return 0;

    *x = aux->pProx->item;

}

//inserir
int THash_Insere(THash *hash, TItem x){
    if (THash_PesquisaCelula(hash, x.nome) == NULL){
        TLista_Insere(&hash->v[THash_H(hash, x.nome)], x);
        hash->n++;
        return 1;
    }
    return 0;
}

//remover
int THash_Remove(THash *hash, TItem *x){
    TCelula *aux = THash_PesquisaCelula(hash, x->nome);

    if(aux == NULL) return 0;

    TLista_Remove(&hash->v[THash_H(hash, x->nome)], aux, x);
    hash->n--;
    return 1;
}

/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/

//ENDEREÇAMENTO ABERTO - TRATAMENTO DE COLISÕES

#define VAZIO "!!!!!!!!!!!\0"
#define N 10 // tamanho da chave string
#define M 20 // tamanho do vetor

typedef char TChave[N];

typedef struct{
    int matricula;
    float nota;
    TChave nome;
}TItem;

typedef TItem TDicionario[M];

//INICIA

void TDicionario_Inicia(TDicionario dic){
    for(int i = 0; i < M; i++){
        memcpy(dic[i].nome, VAZIO, N);
    }
}

int TDicionario_Pesquisa(TDicionario dic, TChave chave, int p){
    int i = 0;
    int ini = h(chave, p);

    while(strcmp(dic[(ini + i) % M].nome, VAZIO) != 0 &&
          strcmp(dic[(ini + i) % M].nome, chave) != 0 && i < M)
        i++;

    if(strcmp(dic[(ini + i) % M].nome, chave) == 0)
        return (ini + i) % M;
    return -1; //pesquisa sem sucesso
}

int TDicionario_Insere(TDicionario dic, TItem x, int p){
    if(TDicionario_Pesquisa(dic, x.nome, p) >= 0)
        return 0; //chave ja existe no dicionario

    int i = 0;
    int ini = h(x.nome, p);
    while(strcmo(dic[(ini + i) % M].nome, VAZIO) != 0 && i < M)
        i++;

    if(i < M){
        dic[(ini + i) % M] = x;
        return 1;
    }
    return 0;
}

int TDicionario_Retira(TDicionario dic, TItem *x, int p){
    int i = TDicionario_Pesquisa(dic, x->nome, p);
    if(i == -1) return 0; // chave não encontrada

    memcpy(dic[i].nome, VAZIO, N);
    return 1;

}















// chamada do hashmap (funcao principal)
int main(){
    return 0;
}