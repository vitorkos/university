#include<stdio.h>

int main()
{
    int vet[20];
    int aux[20];
    int j = 0;
    int i;
    printf("enter the values of the vector: ");
    for(i = 0; i < 20; i++){
        printf("enter the value of the position %d: ", i);
        scanf("%d", &vet[i]);
    }

    for(i = 20; i != 10; i--){
        aux[j] = vet[i];
        j++;
    }

    j = 10;

    for(i = 10; i != 0; i--){
        aux[j] = vet[i];
        j++;
    }

    for(int i = 0; i < 20; i++){
        printf("%d -  ", aux[i]);
    }

    return 0;
}