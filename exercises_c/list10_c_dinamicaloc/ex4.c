#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **mat1, **mat2, **soma, c, l, i, j;

    printf("enter the number of lines: ");
    scanf("%d", &l);
    printf("enter the number of columns: ");
    scanf("%d", &c);

    mat1 = (int **) malloc(l * sizeof(int *));
    mat2 = (int **) malloc(l * sizeof(int *));
    soma = (int **) malloc(l * sizeof(int *));
    for(i = 0; i < l; i++){
        mat1[i] = (int *) malloc(c * sizeof(int));
        mat2[i] = (int *) malloc(c * sizeof(int));
        soma[i] = (int *) malloc(c * sizeof(int));
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("enter the matrix1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("enter the matrix2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            soma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("the sum of the two matrices is: ");
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%d ", soma[i][j]);
        }
    }

    return 0;
}