#include<stdio.h>

int main()
{
    int count;
    int n;
    int numero;
    int maior = 0;
    int menor = 0;

    printf("insira um numero: ");
    scanf("%d", &n);

    for (count = 1; count <= n; count++){
        printf("numero = ");
        scanf("%d", &numero);


        if (numero > menor){
            menor = numero;
        }
        else{}
        if (numero < maior){
            maior = numero;
        }
        else{}
    }
    printf("o maior numero eh %d e o menor %d", maior, menor);

    return 0;

}

