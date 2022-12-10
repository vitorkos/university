#include <stdio.h>

int main()
{
    printf("PRICES\n\nCODES --- PRICES\n1 --- R$5,30\n2 --- R$6,00\n3 --- R$3,20\n4 --- R$2,50\n");

    int code;
    float qnt, total;
    printf("enter the code of the product: ");
    scanf("%d", &code);
    printf("enter the quantity purchased: ");
    scanf("%f", &qnt);

    if (code == 1){
        total = (qnt *5.30);
        if(qnt * 5.30 > 15){
            printf("the total to be paid is R$%.2f", total + (total * 0.15));
        }
        else{
            printf("the total to be paid is R$%.2f", total);
        }
    }
    if (code == 2){
        total = (qnt *6.00);
        if(qnt * 6.00 > 15){
            printf("the total to be paid is R$%.2f", total + (total * 0.15));
        }
        else{
            printf("the total to be paid is R$%.2f", total);
        }
    }
    if (code == 3){
        total = (qnt *3.20);
        if(qnt * 3.20 > 15){
            printf("the total to be paid is R$%.2f", total + (total * 0.15));
        }
        else{
            printf("the total to be paid is R$%.2f", total);
        }
    }
    if (code == 4){
        total = (qnt *2.50);
        if(qnt * 2.50 > 15){
            printf("the total to be paid is R$%.2f", total + (total * 0.15));
        }
        else{
            printf("the total to be paid is R$%.2f",total);
        }
    }

    return 0;
}