#include <stdio.h>

int main()
{
    int number, count = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    for(int i = 1; i <= number; i++)
    {
        if(number % i == 0)
        {
            count++;
        }
    }
    printf("The number %d has %d divisors", number, count);

    return 0;
}