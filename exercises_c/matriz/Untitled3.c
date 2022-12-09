#include<stdio.h>

int main()
{
    int i, j;
    int matriz[5][3];
    int m = 0;
    int k;
    int vet[k];

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            printf("insira o valor da matriz[%d %d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            for(k = 0 ;matriz[i][j] % 7 == 0; k++){
                vet[k] = matriz[i][j];
            }
        }
    }
    printf("os multiplos de 7 na matriz sao %d",vet );
    return 0;
}
