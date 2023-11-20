#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}

struct item{
    int valor;
};

typedef struct item Item;

void selectionSort(Item* v, int n){
    int i, j, min;
    for(i = 0; i < n; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(v[j].valor < v[min].valor){
                min = j;
            }
            troca(v[i], v[min]);
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    Item* itens = (Item *)malloc(n * sizeof(Item));
    for(int i = 0; i < n; i++){
        scanf("%d", &itens[i].valor);
    }
    selectionSort(itens, n);
    for(int i = 0; i < n; i++){
        printf("%d\n", itens[i].valor);
    }
    free(itens); return 0;
}