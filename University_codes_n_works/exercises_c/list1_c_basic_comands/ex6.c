#include <stdio.h>

int main()
{
    float km, liters;

    printf("enter the past kilometers: ");
    scanf("%f", &km);
    printf("enter the liters used: ");
    scanf("%f", &liters);

    printf("the usage of kilometer per liter is %.2f", km / liters);
    
    return 0;
}