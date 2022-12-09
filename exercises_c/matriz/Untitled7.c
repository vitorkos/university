#include<stdio.h>

void lematriz(int mat[][col], int m, int n)
{
    for(int i = o; i < 4; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &,mat[i][j])
        }
    }
}

int maiorelemento(int mat[4][5], int m, int n)
{
    int maior = mat [0][0];
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            if maior <  mat[i][j]{
                maior = mat[i][j];
            }
        }
    }
}
#define lin 4,  col 5
int main()
{
    int mat[lin][col];
    lematriz(mat, 4, 5);
    int resultado = maiorelemento(mat, 4, 5);
    printf("%d", resultado)
}
