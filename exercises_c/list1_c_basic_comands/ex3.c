#include <stdio.h>

int main()
{
    int m, n, x, y;
    printf("insert the values of m, n, x and y: ");
    scanf("%d%d%d%d", &m, &n, &x, &y);

    int multmn = m * n;
    int multxy = x * y;

    printf("the diference between the product of M x N and X x Y is %d", multmn - multxy);

    return 0;
}