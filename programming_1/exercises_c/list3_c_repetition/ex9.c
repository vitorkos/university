#include<stdio.h>

int main()
{
    int n, medium = 0, sum = 0;
    printf("Enter a number of numbers to be insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int number;
        printf("Enter the %d number: ", i);
        scanf("%d", &number);
        sum += number;
    }
    medium = sum / n;
    printf("The medium of the numbers is %d", medium);

    return 0;
}