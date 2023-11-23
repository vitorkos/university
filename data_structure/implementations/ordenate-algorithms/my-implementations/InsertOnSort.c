// o insertonsort procura comparar o item inserido com todos os anteriores, até ordenar

#include <stdio.h>
#include <stdlib.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}


struct item{
    int info;
};

typedef struct item Item;

void insertOnSort(Item* v, int n){
    int i, j;
    for(i = 1; i < n; i++){
        for(j = i; j > 0; j--){
            if(v[j - 1].info > v[i].info){
                troca(v[j - 1], v[i]);
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
    insertOnSort(vetor, n);
    for(int i = 0; i <n; i++){
        printf("%d", vetor[i].info);
    }
    free(vetor);
    return 0;
}