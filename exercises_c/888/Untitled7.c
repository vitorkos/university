#include<stdio.h>

int maior(int x, int y)
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
    int x, y, m;

    printf("insira dois valores: ");
    scanf("%d%d", &x, &y);

    m = maior(x, y);

    printf("o maior dos numeros eh %d", m);

    return 0;
}
