#include<stdio.h>

int f_bigger(int x, int y)
{
    int m;
    if (x > y){
        m = x;
    }
    else{
        m = y;
    }
    return m;
}

int main()
{
    int x, y;

    printf("enter two numbers:");
    scanf("%d%d", &x, &y);

    int bigger = f_bigger(x, y);

    printf("the bigger number is %d", bigger);

    return 0;
}
