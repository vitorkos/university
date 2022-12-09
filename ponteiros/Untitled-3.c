//certo

#include<stdio.h>

int tamanho()
{
    int t;
    printf("insira o tamanho do vetor: ");
    scanf("%d", &t);

    return t;
}

void vetores(int tam, int *vet)
{
    int i;
    for(i = 0; i != tam ; i++){
        printf("insira o valor de: vetor[%d]", i);
        scanf("%d", &vet[i]);
    }
}

int maior(int *vet, int tam, int *pos)
{
    int maior = 0;
    int i;
    for(i = 0; i != tam; i++){
        if(vet[i] > maior){
            maior = vet[i];
            pos = i;
        }
        else{}
    }

    return pos;
}


int main()
{
    int tam;
    tam = tamanho();

    int vetor[tam];

    int *vet;
    vet = &vetor;

    vetores(tam, vet);

    int posicao;
    int *pos;
    pos = &posicao;

    int maiornum;
    maiornum = maior(vet, tam, pos);

    printf("a posicao do maior numero dentro do vetor eh %d", maiornum);
    return 0;

}