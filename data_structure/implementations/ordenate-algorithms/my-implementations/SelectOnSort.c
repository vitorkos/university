//selection sort procura sempre encontrar o valor minimo e troca-lo

#include <stdio.h>
#include <stdlib.h>

#define troca(A, B){struct item c = A; A = B ; B = c;}


struct item{
    int info;
};

typedef struct item Item;

void selectOnSort(Item* v, int n){
    int i, j, min;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(v[j].info < v[min].info){
                min = j;
            }
            troca(v[i], v[min]);
        }
    }

}


int main(){
    int n; scanf("%d", &n);
    Item* vetor = (Item*)malloc(n*sizeof(Item));
    for(int i = 0; i <n; i++){
        scanf("%d", &vetor[i].info);
    }
    selectOnSort(vetor, n);
    for(int i = 0; i <n; i++){
        printf("%d", vetor[i].info);
    }
    free(vetor);
    return 0;
}