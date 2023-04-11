#include <stdio.h>

int f_exp(int x, int n)
{
    if (n == 0){
        return 1;
    }
    
    return x * f_exp(x, n -1 );
}

void main()
{
    int n, x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("Enter the expoent of the number: ");
    scanf("%d", &n);

    int result = f_exp(x, n);
    printf("The result is %d\n", result);
}