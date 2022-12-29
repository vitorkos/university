#include <stdio.h>

void f_average(float no1, float no2, float result1, float result2, float result3)
{
    result1 = (no1 + no2) / 2;
    result2 = (no1 * 3 + no2 * 2) / 10;
    result3 = 2 / (1 / no1 + 1 / no2);
}

int main()
{
    char option;
    float no1, no2, result1, result2, result3;
    printf("Enter the note 1: ");
    scanf("%f", &no1);
    printf("Enter the note 2: ");
    scanf("%f", &no2);

    printf("Enter the operation: ( A - arithmetic average, P - weighted average, H - harmonic average) ");
    scanf(" %c", &option);

    f_average(no1, no2, result1, result2, result3);

    if(option == 'A')
    {
        printf("The arithmetic average is: %.2f", result1);
    }
    else if(option == 'P')
    {
        printf("The weighted average is: %.2f", result2);
    }
    else if(option == 'H')
    {
        printf("The harmonic average is: %.2f", result3);
    }
    else
    {
        printf("Invalid option");
    }

    return 0;
}