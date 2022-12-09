#include<stdio.h>

int main()
{
    int m, n;
    int par = 0;
    int impar = 0;
    printf("insira a ordem da matriz onde M(linha) seja maior igual a 2 e menor igual a 15 e N(coluna maior igual a 3 e menor igual a 20)");
    scanf("%d%d",&m, &n );

    int matriz[m][n];
    int i, j;

    for (i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("entre com da matriz [%d %d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < m; i++){
        for(j = 0; j < n; j++){
           if (matriz[i][j] % 2 == 0){
               par = par + matriz[i][j];
           }
           else{
                impar = impar + matriz[i][j];
           }
        }
    }

    printf("a soma dos valores pares eh de %d e dos impares %d", par, impar);

    return 0;
}
