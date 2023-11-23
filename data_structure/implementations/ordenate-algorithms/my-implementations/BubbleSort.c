// o insertonsort procura comparar o item inserido com todos os anteriores, até ordenar

#include <stdio.h>
#include <stdlib.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}


struct item{
    int info;
};

typedef struct item Item;

void bubbleSort(Item* v, int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = 1; j < n - i; j++){
            if(v[j].info < v[j - 1].info){
                troca(v[j], v[j - 1]);
            }
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    Item* vetor = (Item*)malloc(n*sizeof(Item));
    for(int i = 0; i <n; i++){
        scanf("%d", &vetor[i].info);
    }
    bubbleSort(vetor, n);
    for(int i = 0; i <n; i++){
        printf("%d", vetor[i].info);
    }
    free(vetor);
    return 0;
}