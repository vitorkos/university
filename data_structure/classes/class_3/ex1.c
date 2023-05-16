#include <stdio.h>
#include <stdlib.h>

void setWeight(int vet[], int n, float sum){
    for(int i = 0; i < n; i++){
        printf("Enter the weight %d: ", i);
        scanf("%f", &vet[i]);
        sum += vet[i];
    }
}

int main(){
    int n;
    float sum, medium;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    int *vet;
    vet = (int *)malloc(n * sizeof(int));
    setWeight(vet ,n, sum);
    printf("The medium weight is %.2f", medium);
    free(vet);
    return 0;
}