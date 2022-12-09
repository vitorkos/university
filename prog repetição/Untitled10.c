#include<stdio.h>

int main()
{
    int count;
    int n;
    int idade;
    int menos18 = 0;
    int mais30 = 0;

    printf("insira a quantidade de pessoas: ");
    scanf("%d", &n);

    for(count = 1; count <= n; count++){
        printf("insira a idade: ");
        scanf("%d", &idade);
        if (idade >= 30){
            mais30 = mais30 + 1;
        }
        else if (idade <= 18){
            menos18 = menos18 + 1;
        }
    }
    printf("a quantidade de pessoas com mais de 30 anos sao de %d", mais30);
    printf("a quantidade de pessoas com menos de 18 anos sao de %d", menos18);

    return 0;
}
