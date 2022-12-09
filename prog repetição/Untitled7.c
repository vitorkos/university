#include<stdio.h>
//n compila direito
int main()
{
    int qnt, n;
    int count = 1;
    int conta;
    int mult;

    printf("insira a quantidade de numeros da multiplicação: ");
    scanf("%d", &qnt);

    while(count <= qnt){
        printf("numero = ");
        scanf("%d", &n);

        mult = n * n;
        conta = conta + mult;

        printf("%d", conta);

        count++;
    }
    return 0;
}
