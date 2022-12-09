#include<stdio.h>

int maior(int x, int y, int a)
{
    int m;
    if (x > y && x > a){
        m = x;
    }
    else if (y > x && y > a){
        m = y;
    }
    else{
        m = a;
    }
    return m;
}

int main()
{
    int x, y, a, m;

    printf("insira tres valores: ");
    scanf("%d%d%d", &x, &y, &a);

    m = maior(x, y, a);

    printf("o maior dos numeros eh %d", m);

    return 0;
}
