#include<stdio.h>

int main()
{
    int divider, dividend = 1, division, sum = 0;

    for(divider = 1; divider <= 50; divider++){
        printf("(%d / %d ) + ", dividend, divider);
        division  = dividend / divider;
        sum = sum + division;
        dividend = dividend + 2;
    }
    printf("the sum of the divisions is %d", sum);
}