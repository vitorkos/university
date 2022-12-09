// ponteiros  com matriz, vetor e função

#include<stdio.h>

void atribuicao(int *p, int n)
{
    int i;
    for(i = 0; i != n; i++){
        printf("insira o valor no vetor %d", i);
        scanf("%d", &p[i]);
    }
}

int main()
{
    int n;

    printf("insira a quantidade de itens do aray: ");
    scanf("%d", &n);

    int vet[n];
    int *p;
    p = vet;

    atribuicao(*p, n);

    return 0;
}
