#include<stdio.h>

int main()
{
    int n, i, aux, j;
    printf("insira a quantidade de numeros do vetor");
    scanf("%d", &n);
    int vet[n];

    for(i = 0; i < n; i++){
        printf("o valor do vetor %d eh: ", vet[i]);
        scanf("%d", &vet[i]);
    }
    for (i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if (vet[j] < vet[i]){
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d\n", vet[i]);
    }
    return 0;
}
