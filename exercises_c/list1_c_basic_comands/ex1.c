#include <stdio.h>

int main()
{
    int n;
    printf("insert a number: ");
    scanf("%d", &n);

    printf("the number before %d is %d and the number after is %d", n, n - 1, n + 1);

    return 0;
}