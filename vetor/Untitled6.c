#include<stdio.h>

int main()
{
    int i;
    int vet[21];

    for(i = 0; i < 21; i++){
        printf("insira o valor do vetor %d", vet[i]);
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < 21; i++){
        if(vet[21] == vet[i]){
            printf("o valor igual esta na posicao %d", i);
        }
        else{}
    }
    return 0;
}
