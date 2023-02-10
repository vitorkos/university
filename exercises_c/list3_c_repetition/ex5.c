#include<stdio.h>

int main()
{
    int x, y;
    printf("enter a number to be the first number of the interval and a number to be the last number of the interval: ");
    scanf("%d%d", &x, &y);

    printf("the number that can be divided by 5 and the rest of the division is 2 or 3 is: \n");
    while(x < y){
        if (x % 5 == 2 || x % 5 == 3){
            printf("%d - ", x);
        }
        x++;
    }
    return 0;
}