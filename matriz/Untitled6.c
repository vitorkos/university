#include<stdio.h>

int main()
{
    int i, j;
    int m, soma = 0;
    scanf("%d", &m);//tamanho da matriz
    int mat[m][m];
    for(i = 0; i < m; i++){
        for (j = 0; j< m; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            if j > i{
                soma += mat[i][j];
            }
        }
        printf("%d", soma);
    }

    return 0;
}
