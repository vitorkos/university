//certo

#include<stdio.h>

int f_bigger(int *vet, int tam)
{
    int i;
    int bigger = 0;
    for(i = 0; i != tam; i++){
        if(vet[i] > bigger){
            bigger = vet[i];
        }
        else{}
    }

    return bigger;
}

int f_smaller(int *vet, int tam)
{
    int i;
    int smaller = 100000000000000000000000000;
    for(i = 0; i != tam; i++){
        if(vet[i] < smaller){
            smaller = vet[i];
        }
        else{}
    }

    return smaller;
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

    int find_bigger;
    find_bigger = f_bigger(vet, n);

    int find_smaller;
    find_smaller = f_smaller(vet, n);

    printf("the smaller number is: %d and the bigger number is: %d", find_smaller, find_bigger);

    return 0;
}