#include <stdio.h>

int main()
{
    printf("\n\nCODE --- OFFICE --- ADJUSTMENT\n1 --- SELLER --- 10%\n2 --- OFFICE ASSISTANT --- 7%\n3 --- NURSING ASSISTANT --- 12%\n4 --- LIBRARIAN --- 11%\n");

    int code;
    float qnt, total;
    printf("enter the code: ");
    scanf("%d", &code);
    printf("enter the salary of the worker");
    scanf("%f", &qnt);

    if (code == 1){
        total = (qnt *0.10);
        printf("the value of the adjustment was %.2f and the final wage R$%.2f", total, total + qnt);
    }
    if (code == 2){
        total = (qnt *0.07);
        printf("the value of the adjustment was %.2f and the final wage R$%.2f", total, total + qnt);
    }
    if (code == 3){
        total = (qnt *0.12);
        printf("the value of the adjustment was %.2f and the final wage R$%.2f", total, total + qnt);
    }
    if (code == 4){
        total = (qnt *0.11);
        printf("the value of the adjustment was %.2f and the final wage R$%.2f", total, total + qnt);
    }

    return 0;
}