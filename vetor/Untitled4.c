#include<stdio.h>

int f1(int vet[], int n)
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

int f2(int vet[], int n)
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
    int n, i, mai, men;
    printf("insira a quantidade de numeros do vetor: ");
    scanf("%d", &n);
    int vet[n];

    for(i = 0; i < n; i ++){
        printf("insira o valor do vetor %d", vet[i]);
        scanf("%d", &vet[i]);
    }
    mai = f1(vet, n);
    men = f1(vet, n)

    printf("%d\n%d", mai, men);

}
