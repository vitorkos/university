#include<stdio.h>

void f_count(int vector[], int n)
{
    int count = 0;
    for(int i = 0; i <= n - 1; i++){
        if (vector[i] == vector[n]){
            count++;
        }
        else{}
    }
    printf("the number %d is repeated %d times", vector[n], count);
}

int main()
{
    int n;
    printf("enter the size of the vector:");
    scanf("%d", &n);
    int vector[n];

    for (int i = 0; i <= n - 1; i++){
        printf("enter the %d number:", i);
        scanf("%d", &vector[i]);
    }

    f_count(vector, n);

    return 0;
}