#include<stdio.h>

int main()
{
    int count = 1;
    int mult;

    printf("the multiplication table of 7 is:");

    while (count <= 10){
        mult = 7 * count;
        printf("7 x %d = %d ",count, mult);
        count++;
    }
    return 0;
}