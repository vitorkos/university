#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}

struct item{
    int valor;
};

typedef struct item Item;

void bubbleSort(Item* v, int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 1; j < n-i; j++){
            // o i é a quantidade de itens que foram ordenados, que foram jogados no fim do vetor
            // n - i faz com que a iteração não passe pelos valores já ordenados
            if(v[j].valor < v[j-1].valor){
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
    bubbleSort(itens, n);
    for(int i = 0; i < n; i++){
        printf("%d\n", itens[i].valor);
    }
    free(itens); return 0;
}