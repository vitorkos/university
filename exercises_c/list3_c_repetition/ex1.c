#include<stdio.h>

int main()
{
    int multiplying, multiplier, result;

    for(multiplier = 1; multiplier <= 10; multiplier++){
        printf("multiplication of %d\n", multiplier);
        for(multiplying = 1; multiplying <= 10; multiplying++){
            result = multiplier * multiplying;
            printf("%d x %d = %d\n",multiplier, multiplying, result);
        }
    }
    return 0;
}