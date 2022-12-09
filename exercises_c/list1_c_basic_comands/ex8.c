#include <stdio.h>

int main()
{
    float cost;
    printf("who much did you spend: $ ");
    scanf("%f", &cost);

    float waiter = cost * 0.10;
    printf("the total plus the waiter: $%.2f", waiter + cost);

    return 0;
}