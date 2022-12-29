#include<stdio.h>
#include<stdlib.h>

void f_insert(int vetx[], int vety[], int tam)
{
    int i;

    for(i = 0; i< tam; i++){
        printf("enter the vetor[%d]: ", i);
        scanf("%d", &vetx[i]);
    }
    for(i = 0; i< tam; i++){
        printf("enter the vetor[%d]: ", i);
        scanf("%d", &vety[i]);
        }
}

int *f_sum(int vetx[], int vety[], int tam)
{
    int i;
    int *sumav;
    sumav = (int *)malloc (tam *sizeof(int));

    for(i = 0; i < tam; i++){
        sumav[i] = vetx[i] + vety[i];
    }
    return sumav;
}

int main()
{
    int n;

    printf("enter the size of the vectors:");
    scanf("%d", &n);

    int vetx[n];
    int vety[n];


    f_insert(vetx, vety, n);

    int *sum_vet = f_sum(vetx, vety, n);

    printf("the sum of the vectors is: %d", *sum_vet);

    free(sum_vet);

    return 0;
}