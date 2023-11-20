#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}

struct item{
    int valor;
};

typedef struct item Item;

void selectionSort(Item *v, int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = n-1; j > i; j--){
            if(v[j-1].valor > v[j].valor){
                troca(v[j-1], v[j]);
            }
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