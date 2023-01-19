#include<stdio.h>

int main()
{
    int n, i, aux, j;
    printf("enter the size of the vector:");
    scanf("%d", &n);
    int vet[n];

    for(i = 0; i < n; i++){
        printf("enter the %d number:", i);
        scanf("%d", &vet[i]);
    }
    for (i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if (vet[j] < vet[i]){
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
            else{}
        }
    }
    for(i = 0; i < n; i++){
        printf("%d - ", vet[i]);
    }
    return 0;
}
