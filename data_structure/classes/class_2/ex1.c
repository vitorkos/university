#include <stdio.h>

int main()
{
    float vet[10];
    float sum = 0;
    for(int i = 0; i < 10; i++){
        printf("Enter the age person %d: ", i);
        scanf("%f", &vet[i]);
        sum += vet[i];    
    }
    float medium = sum / 10;
    printf("The medium age is %.2f", medium);
    return 0;
}