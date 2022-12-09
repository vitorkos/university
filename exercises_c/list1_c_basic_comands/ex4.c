#include <stdio.h>

int main()
{
    float dolar = 4.87;
    float n;
    printf("insert a number of reais to be converted: R$ ");
    scanf("%f", &n);

    printf("$%.2f dolars have been converted to R$%.2f reais\n", n, n * dolar);

    return 0;
}