#include<stdio.h>

int numero(int a, int b)
{
    int n = b - a;


    return n;
}



int main ()
{
    int a = 5;

    int b = 15;

    printf("%d", numero(a, b));

    return 0;
}
