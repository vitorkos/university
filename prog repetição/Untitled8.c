#include<stdio.h>

int main()
{
    int count = 1;
    int mult;

    printf("os 10 primeiros multiplos de 7 são: ");

    while (count <= 10){
        mult = 7 * count;
        printf("%d ", mult);
        count++;
    }
    return 0;
}
