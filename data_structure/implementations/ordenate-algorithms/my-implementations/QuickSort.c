#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void troca(Item* vet, int i, int j) {
    Item aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

struct item{
    int valor;
};

typedef struct item Item;

int particiona(Item* v, int inicio, int fim){
    int pivo, pivo_indice, i;
    pivo = v[fim].valor;
    pivo_indice = inicio;
    for(i = inicio; i < fim; i++){
        if(v[i].valor <= pivo){
            troca(v, i, pivo_indice);
            pivo_indice++;
        }
    }
    troca(v, pivo, fim);
}

void quickSort(Item* v, int inicio, int fim){
    if(inicio < fim){
        int pivot_indice = particiona(v, inicio, fim);
        quickSort(v, inicio, pivot_indice);
        quickSort(v, pivot_indice + 1, fim);
    }
}

int main(){
    int n; scanf("%d", &n);
    Item* itens = (Item *)malloc(n * sizeof(Item));
    for(int i = 0; i < n; i++){
        scanf("%d", &itens[i].valor);
    }
    quickSort(itens, 0, n -1);
    for(int i = 0; i < n; i++){
        printf("%d\n", itens[i].valor);
    }
    free(itens); return 0;
}