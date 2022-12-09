#include<stdio.h>
#include<stdlib.h>

int main()
{
    //a
    int a, b, c;
    a = 10;
    b = 4;
    c = 2;

    int resultado1;
    resultado1 = ( a * b ) / c;
    printf("\n%d", resultado1);

    //b
    int resultado2;
    resultado2 = (a * a) + b + (5 * c);
    printf("\n%d", resultado2);

    //c
    int resultado3;
    resultado3 = (a * b * c) + b +((c / 3)* 5) - 1;
    printf("\n%d", resultado3);

    //d
    int resultado4;
    resultado4 = ((a * b * c) * (a * b * c) * (a * b * c)) /2;
    printf("\n%d", resultado4);

return 0;
}
