#include <stdio.h>

int f_sum(int n)
{
    if(n == 0){
        return 0;
    }
    else{
        return n + f_sum(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = f_sum(n);
    printf("%d\n", result);

    return 0;
}