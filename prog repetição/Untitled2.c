#include<stdio.h>

int main()
{
    int num, den;
    float resultado = 0;
    int divisor = 1;
    printf("insira um valor: ");
    scanf("%d", &num);

    while (divisor == 50){
        resultado = num / divisor;
        printf(" resultado = %f divisores", resultado);
        divisor++;
    }
    return 0;

}
