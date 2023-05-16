#include <stdio.h>
#include <stdlib.h>

void setGrade(int vet[], int n, float sum, float bigger){
    for(int i = 0; i < n; i++){
        printf("Enter the grade %d: ", i);
        scanf("%f", &vet[i]);
        sum += vet[i];
        if(vet[i] > bigger){
            bigger = vet[i];
        }
    }
}

int main(){
    int n;
    float sum, medium, bigger = 0;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    int *vet;
    vet = (int *)malloc(n * sizeof(int));
    setGrade(vet ,n, sum, bigger);
    printf("The medium grade is %.2f", medium);
    free(vet);
    return 0;
}