#include<stdio.h>

int main()
{
    int lado1, lado2, lado3;
    printf("insira a medida dos lados dos triangulos: \n");
    scanf("%d%d%d", &lado1, &lado2, &lado3);

    if (lado1 == lado2 && lado2 == lado3){
        printf("o triangulo eh equilatero");
    }
    else if(lado1 == lado2 || lado1 == lado3 || lado3 == lado2){
        printf("o triangulo eh isosceles");
    }
    else{
        printf("o triangulo eh escaleno");
    }
    return 0;
}
