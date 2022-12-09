#include<stdio.h>
#include<stdlib.h>

int main()
{
    int identif;
    printf("\n Qual o numero de identificacao do funcionario? \n");
    scanf("%d", &identif);

    int hrs;
    printf("\n Quantas horas ele trabalhou? \n");
    scanf("%d", &hrs);

    int salariohr;
    salariohr = 2;

    int salario;
    salario = hrs * salariohr;

    printf("\n O numero de identiicacao do funcionario é %d", identif);
    printf("\n o salario do funcionario é de %d", salario);

return 0;
}
