#include<stdio.h>

f_divisors(int number)
{
    int divisors = 0;
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            divisors++;
        }
    }
    return divisors;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int number_divisors = f_divisors(number);

    printf("The number %d has %d divisors", number, number_divisors);
    return 0;
}