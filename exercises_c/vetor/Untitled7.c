#include<stdio.h>

int main()
{

    int n;
    int quants = 0;
    int i = 0;
    while(n != -1){
        int vet[i];
        printf("insira um valor para o vetor %d: ");
        scanf("%d", &n);
        vet[i] = n;
        if (vet[i] >= 10 && vet[i] <= 50){
            quants++;
        }
        i++;
    }


    return 0;
}
