//certo

#include<stdio.h>

int negativos (int *vet, int tam)
{
    int count = 0;
    int i;
    for(i = 0; i != tam; i++){
        if(vet[i] < 0){
            count++;
        }
        else{}
    }

    return count;
}

int main()
{
    int tam;
    printf("insira o tamanho do vetor: ");
    scanf("%d", &tam);

    int vetor[tam];
    int *vet;
    vet = &vetor;

    int i;
    for(i = 0; i != tam; i++){
        printf("insira o valor da posicao %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }

    int neg;
    neg = negativos(vet, tam);

    printf("a quantidade de numeros negativos do vetor eh de %d", neg);

    return 0;

}