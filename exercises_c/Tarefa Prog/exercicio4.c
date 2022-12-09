#include<stdio.h>
#include<stdlib.h>

int main()
{
    //declaração das variaveis

    float valorreal;
    float dolar;
    float convert;
    dolar = 4.87;

    printf("/n Insira o valor a ser convertido de doláres para reais:\n");
    scanf("%f", &valorreal);

    convert = valorreal * dolar;

    printf("A conversão ficaria em: %f", convert);

return 0;
}
