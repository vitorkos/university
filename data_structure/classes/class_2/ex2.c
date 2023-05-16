#include <stdio.h>

int main()
{
    int mat[1][1];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("Enter the value [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    int determinant = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    printf("The determinant of the matrix is %d", determinant);
}