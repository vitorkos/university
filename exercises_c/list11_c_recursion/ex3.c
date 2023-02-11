#include <stdio.h>

void f_bin(int n)
{
    if (n == 0){
        return;
    }
    f_bin(n / 2);
    printf("%d", n % 2);
}

void main()
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("The binary equal to %d is: ", n);
    f_bin(n);
    printf("\n")
}