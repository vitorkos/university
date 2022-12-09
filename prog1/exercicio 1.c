#include<stdio.h>

int main()
{
    int num1, num2, num3;
    printf("insira 3 numeros: \n");
    scanf("%d%d%d", &num1, &num2, &num3);

    if(num1 < num2 && num1 < num3){
        printf("o menor numero eh %d ", num1);
    }
    else if(num2 < num1 && num2 < num3){
        printf("o menor numero eh %d", num2);
    }
    else if(num3 < num1 && num3 < num2){
        printf("o menor numero eh %d", num3);
    }
    return 0;
}
