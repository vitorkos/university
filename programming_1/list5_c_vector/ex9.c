#include<stdio.h>

void f_average(int vet[], int j){
    int i;
    int sum = 0;
    int average = 0;
    for(i = 0; i < j; i++){
        sum += vet[i];
    }
    average = sum / 20;
    printf("the average of the vector is: %d", average);
}

int main()
{
    int n = 0, j = 0;
    int vet[n];
    while(n != -1){
        
        printf("enter a value to the vector %d : (enter -1 to stop):", n);
        scanf("%d", &n);
        vet[n] = n;
        n++;
    }
    
    f_average(vet, j);

    return 0;
}