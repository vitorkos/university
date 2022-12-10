#include<stdio.h>
#include<stdlib.h>

void atribui(int vetx[], int vety[], int tam)
{
    int i;

    for(i = 0; i< tam; i++){
        printf("insira o vetor[%d]: ", i);
        scanf("%d", &vetx[i]);
    }
    for(i = 0; i< tam; i++){
        printf("insira o vetor[%d]: ", i);
        scanf("%d", &vety[i]);
        }
}

int *soma(int vetx[], int vety[], int tam)
{
    int i;
    int *somav;
    somav = (int *)malloc (tam *sizeof(int));

    for(i = 0; i < tam; i++){
        somav[i] = vetx[i] + vety[i];
    }
    return somav;
}

int main()
{
    int n;

    printf("insira o tamanho dos vetores: ");
    scanf("%d", &n);

    int vetx[n];
    int vety[n];


    atribui(vetx, vety, n);

    int *r = soma(vetx, vety, n);

    printf("a soma entre os vetores eh %d", r);

    free(r);

    return 0;
}
