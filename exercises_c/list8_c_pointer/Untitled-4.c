//certo

#include<stdio.h>

int achar1(int *vet, int tam)
{
    int i;
    int maior = 0;
    for(i = 0; i != tam; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
        else{}
    }

    return maior;
}

int achar2(int *vet, int tam)
{
    int i;
    int menor = 100000000000000000000000000;
    for(i = 0; i != tam; i++){
        if(vet[i] < menor){
            menor = vet[i];
        }
        else{}
    }

    return menor;
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
        printf("insira o valor de %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }

    int f1;
    f1 = achar1(vet, tam);

    int f2;
    f2 = achar2(vet, tam);

    printf("o menor numero do vetor eh %d e o maior %d", f2, f1);

    return 0;


}