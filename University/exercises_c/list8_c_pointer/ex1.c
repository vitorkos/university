//certo

#include<stdio.h>

int f_negative(int *vet, int tam)
{
    int count = 0;
    int i;
    for(i = 0; i != tam; i++){
        if(vet[i] < 0){
            count++;
        }
        else{}
    }

    return count;
}

int main()
{
    int n;
    printf("enter the size of the vector:");
    scanf("%d", &n);

    int vector[n];
    int *vet;
    vet = &vector;

    int i;
    for(i = 0; i != n; i++){
        printf("enter the %d number:", i);
        scanf("%d", &vet[i]);
    }

    int neg;
    neg = f_negative(vet, n);

    printf("the number of negative numbers is: %d", neg);

    return 0;
}