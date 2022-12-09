#include<stdio.h>
#include<stdlib.h>

int main()
{
    float aperitivo ,comida, bebida, sobremesa;
    printf("\n Quanto foi pago de aperitivo? \n");
    scanf("%f", &aperitivo);

    printf("\n Quanto foi pago de comida? \n");
    scanf("%f", &comida);

    printf("\n Quanto foi pago de bebida? \n");
    scanf("%f", &bebida);

    printf("\n Quanto foi pago de sobremesa? \n");
    scanf("%f", &sobremesa);

    float total;
    total = aperitivo + comida + bebida + sobremesa;

    float garcom;
    garcom = total * 0.10




}
