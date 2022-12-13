#include<stdio.h>

int main()
{
    int n, bigger = 0, smaller = 100000000000;
    printf("Enter a number of numbers to be insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int number;
        printf("Enter the %d number: ", i);
        scanf("%d", &number);

        if(number > bigger)
        {
            bigger = number;
        }
        if(number < smaller)
        {
            smaller = number;
        }
    }

    printf("The bigger number is %d and the smaller number is %d", bigger, smaller);
}