#include<stdio.h>

int main()
{

    int n;
    int count = 0;
    int i = 0;
    while(n != -1){
        int vet[i];
        printf("enter a value to the vector %d : (enter -1 to stop):", i);
        scanf("%d", &n);
        vet[i] = n;
        if (vet[i] >= 10 && vet[i] <= 50){
            count++;
        }
        i++;
    }

    printf("the number of values between 10 and 50 is: %d", count);

    return 0;
}