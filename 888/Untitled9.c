#include<stdio.h>

int div(int num, int i, int divisor){
    for (i = 1; i <= num;i ++ ){
        return divisor = (num % i == 0);
    }
}

int main()
{
    int num, i, divisor, divs;

    printf("insira um numero: ");
    scanf("%d", &num);

    divs = div(num, i, divisor);

    printf("os divisores de %d sao %d", num, divs);

    return 0;
}
