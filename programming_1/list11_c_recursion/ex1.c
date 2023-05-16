#include <stdio.h>

int f_pair(int n)
{
    if (n < 0){
        return 0;
    }
    else{
        if (n % 2 == 0){
            printf("%d\n", n);
        }
        else{
            
        }
    }
    return f_pair(n - 1);
}

int main()
{
    int n;
    printf("Enter a pair number: ");
    scanf("%d", &n);

    f_pair(n);

    return 0;
}