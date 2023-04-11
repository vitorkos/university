#include <stdio.h>

int f_pair(int i, int n) {
    if (i > n) {
        return 0;
    }

    if ((i % 2) == 0) {
        printf("%d\n", i);
    }

    return f_pair(i + 1, n);
}

int main()
{
    int n;
    int i = 0;
    printf("Enter a pair number: ");
    scanf("%d", &n);

    f_pair(i, n);

    return 0;
}