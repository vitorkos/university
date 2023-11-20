#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}

struct item{
    int valor;
};

typedef struct item Item;

void insertSort(Item* v, int n){
    int i, j;
    Item item;
    for(i = 1; i < n; i++){
        for(j = i; j > 0; j--){
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
    insertSort(itens, n);
    for(int i = 0; i < n; i++){
        printf("%d\n", itens[i].valor);
    }
    free(itens); return 0;
}