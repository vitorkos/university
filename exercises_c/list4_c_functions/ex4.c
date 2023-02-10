#include <stdio.h>

int f_power(int x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

int main()
{
    int x, n;
    printf("Enter a number and a power: ");
    scanf("%d %d", &x, &n);

    f_power(x, n);
    int r = f_power(x, n);

    printf("%d to the power of %d is %d", x, n, r);

    return 0;
}