#include<stdio.h>
//n compila direito
int main()
{
    int n, number, multiplication = 1;
    printf("Enter a number of numbers to be insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
       printf("Enter the %d number: ", i);
       scanf("%d", &number);
       if(number % 2 == 0)
       {
           multiplication *= number;
       }
       else{}
    }
    printf("the product of the even numbers is: %d", multiplication);

    return 0;
}