#include<stdio.h>

int main()
{
    int n, i;
    printf("enter the size of the vector:");
    scanf("%d", &n);
    int vector[n];

    for (i = 0; i <= n - 1; i++){
        printf("enter the %d number:", i);
        scanf("%d", &vector[i]);
    }
    printf("the inverted vector is: ");
    for (i = n; i >= 0; i--){
        printf("%d - ", vector[i]);
    }

    return 0;
}