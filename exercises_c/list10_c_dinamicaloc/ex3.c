#include<stdio.h>
#include<stdlib.h>

int main()
{
    int l, c, i, j, count = 0;
    int **mat;

    printf("enter the number of lines: ");
    scanf("%d", &l);
    printf("enter the number of columns: ");
    scanf("%d", &c);

    mat = (int **) malloc(l * sizeof(int *));
    for(i = 0; i < l; i++){
        mat[i] = (int *) malloc(c * sizeof(int));
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("enter the matrix[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] % 7 == 0 && mat[i][j] % 2 != 0){
                count++;
            }
            else{}
        }
    }

    int *vet;
    vet = (int *) malloc (count * sizeof(int));

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] % 7 == 0 && mat[i][j] % 2 != 0){
                vet[i] = mat[i][j];
            }
            else{}
        }
    }

    printf("the numbers that are odd and divisible by 7 are: ");
    for(i = 0; i < count; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}
