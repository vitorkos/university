#include<stdio.h>
#include<stdlib.h>

void f_insert(int **mat, int linha, int coluna)
{
    int i, j;

    mat = (int**)malloc(linha * sizeof(int*));
    for(i = 0; i < linha; i++){
        mat[i] = (int*)malloc(coluna * sizeof(int));
    }

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("enter the number of the position [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int f_findnum(int numero, int **mat, int linha, int coluna)
{
    int i, j, r, a = 1, b = 0;

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            if(numero = mat[i][j]){
                return a;
            }
            else{
                return b;
            }
        }
    }
}

int main()
{
    int l, c, **matrix, num;

    printf("enter the number of lines: ");
    scanf("%d", &l);
    printf("enter the number of columns: ");
    scanf("%d", &c);

    f_insert(matrix, l, c);

    printf("enter the number to find: ");
    scanf("%d", &num);

    int find = f_findnum(num, matrix, l, c);
    
    if(find == 1){
        printf("the number is in the matrix");
    }
    else{
        printf("the number is not in the matrix");
    }

    return 0;
}