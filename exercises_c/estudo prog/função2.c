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

    int n1 = numero(a, b);

    printf("%d", n1);

    return 0;
}
