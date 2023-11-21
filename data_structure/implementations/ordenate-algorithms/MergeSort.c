#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}

struct item{
    int valor;
};

typedef struct item Item;

void mergeSort(Item* v, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio +1 ,fim);
        merge(v, inicio, meio, fim);
    }
}

merge(Item * v, int inicio, int meio, int fim){
    int com1 = inicio, com2 = meio + 1, comAux = 0;
    Item *vetAux = (Item*)malloc(fim - inicio +1 * sizeof(Item));
    while(com1 <= meio && com2 <= fim){
        if(v[com1] <= v[com2]){
            vetAux[comAux] = v[com1];
            com1++;
        }
        else{
            vetAux[comAux] = v[com2];
            com2++;
        }
    }
    while(com1 <= meio){
        vetAux[comAux] = v[com1];
        comAux++;
        com1++;
    }
    while(com2 <= fim){
        vetAux[comAux] = v[com2];
        comAux++;
        com2++;
    }
    for(comAux = inicio; comAux <= fim; comAux++){
        v[comAux] = vetAux[comAux - inicio];
    }

}

int main(){
    int n; scanf("%d", &n);
    Item* itens = (Item *)malloc(n * sizeof(Item));
    for(int i = 0; i < n; i++){
        scanf("%d", &itens[i].valor);
    }
    mergeSort(itens, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d\n", itens[i].valor);
    }
    free(itens); return 0;
}