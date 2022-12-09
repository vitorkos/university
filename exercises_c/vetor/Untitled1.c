#include<stdio.h>

int main()
{
    int n, i;
    printf("insira a quantidade de numeros do vetor: ");
    scanf("%d", &n);
    int vetor[n];

    for (i = 0; i <= n - 1; i++){
        printf("insira o valor do vetor %d: ",i );
        scanf("%d", &vetor[i]);
    }
    printf("a ordem inversa dos numeros eh:");
    for (i = n; i >= 0; i--){
        printf("%d\n", vetor[i]);
    }

    return 0;
}
