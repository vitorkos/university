#include<stdio.h>

int main()
{
    int i, j;
    int m, sum = 0;
    printf("enter the size of the matrix: ");
    scanf("%d", &m);

    int mat[m][m];
    for(i = 0; i < m; i++){
        for (j = 0; j< m; j++){
            printf("enter the value of the position [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            if (j > i){
                sum += mat[i][j];
            }
        }
        printf("the sum of the elements above the diagonal is: %d ");
    }

    return 0;
}
