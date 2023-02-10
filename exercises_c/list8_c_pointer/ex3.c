//certo

#include<stdio.h>

int f_size()
{
    int t;
    printf("enter the size of the vector:");
    scanf("%d", &t);

    return t;
}

void f_vectors(int tam, int *vet)
{
    int i;
    for(i = 0; i != tam ; i++){
        printf("enter the %d number:", i);
        scanf("%d", &vet[i]);
    }
}

int f_bigger(int *vet, int tam, int *pos)
{
    int maior = 0;
    int i;
    for(i = 0; i != tam; i++){
        if(vet[i] > maior){
            maior = vet[i];
            pos = i;
        }
        else{}
    }

    return pos;
}


int main()
{
    int n;
    n = f_size();

    int vector[n];

    int *vet;
    vet = &vector;

    f_vectors(n, vet);

    int position;
    int *pos;
    pos = &position;

    int bigger;
    bigger = f_bigger(vet, n, pos);

    printf("the position of the biggest number is: %d", bigger);

    return 0;
}