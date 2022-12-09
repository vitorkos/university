#include<stdio.h>

int main()
{
    float num1, num2, num3;
    float media;
    printf("insira 3 numeros: \n");
    scanf("%f%f%f", &num1, &num2, &num3);

    media = (num1 + num2 + num3) / 3;

    if (num1 > media || num2 > media || num3 > media ){
        printf(" um dos numeros esta acima da media");
    }
    else if (num1 > media && num2 > media || num1 > media && num3 > media || num2 > media && num3 > media ){
        print("dois dos numeros estam acima da media");
    }
    else{
        print("todos estam acima da media");
    }
}
