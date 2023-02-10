#include<stdio.h>

void f_multiples(int vet[], int n){
    int i;
    int count = 0;
    for(i = 0; i < n; i++){
        if(vet[i] % 7 == 0){
            count++;
        }
    }
    int vet2[count];
    int j = 0;
    for(i = 0; i < n; i++){
        if(vet[i] % 7 == 0){
            vet2[j] = vet[i];
            j++;
        }
    }
    printf("the number of multiples of 7 is: %d");
    for(int i = 0; i < count; i++){
        printf("%d - ", vet2[i]);
    }
}

int main()
{
    int n;
    printf("enter a value to the vector: ");
    scanf("%d", &n);
    int vet[n];

    for(int i = 0; i < n; i++){
        printf("enter the value of the position %d: ", i);
        scanf("%d", &vet[i]);
    }

    f_multiples(vet, n);
}