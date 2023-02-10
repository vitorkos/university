#include<stdio.h>

int f_bigger(int vet[], int n)
{
    int i ;
    int maior = vet[0];
    for(i = 1; i < n; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
    }
    return maior;
}

int f_minor(int vet[], int n)
{
    int i;
    int menor =vet[0];
    for(i = 1; i < n; i++){
        if(vet[i] < menor){
            menor = vet[i];
        }
    }
    return menor;
}

int main()
{
    int n, i;
    printf("enter the size of the vector: ");
    scanf("%d", &n);
    int vet[n];

    for(i = 0; i < n; i ++){
        printf("enter the %d element: ", i);
        scanf("%d", &vet[i]);
    }
    int bigger = f_bigger(vet, n);
    int minor = f_minor(vet, n);

    printf("%d - %d", bigger, minor);

    return 0;
}
