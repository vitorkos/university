#include <stdio.h>

int main()
{
    float coffee = 7.00;
    float pay;

    printf("coffee value: $5\n");
    printf("insert the payment: (only values multiples of 5: $5, 10$...)");
    scanf("%f", &pay);

    float loss = pay - coffee;

    printf("the client losses $%.2f of money", loss);

    return 0;
}