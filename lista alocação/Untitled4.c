#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **mat1, **mat2, **soma, c, l, i, j;

    printf("insira a quantidade de linhas: ");
    scanf("%d", &l);
    printf("insira a quantidade de colunas: ");
    scanf("%d", &c);

    mat1 = (int **) malloc(l * sizeof(int));
    for(i = 0; i < l; i++){
        mat1[i] = (int *) malloc(c * sizeof(int));
    }
    if(mat1 == NULL){
        printf("memoria insuficiente");
    }
    else{
        mat2 = (int **) malloc(l * sizeof(int));
        for(i = 0; i < l; i++){
            mat2[i] = (int *) malloc(c * sizeof(int));
            }
        if(mat2 == NULL){
        printf("memoria insuficiente");
        }
        else{
            for(i = 0; i < l; i++){
                for(j = 0; j < c; j++){
                    printf("insira a matriz 1 [%d][%d]", i, j);
                    scanf("%d", &mat1[i][j]);
                }
            }
            for(i = 0; i < l; i++){
                for(j = 0; j < c; j++){
                    printf("insira a matriz 2 [%d][%d]", i, j);
                    scanf("%d", &mat2[i][j]);
                }
            }
            soma = (int **) malloc(l * sizeof(int));
            for(i = 0; i < l; i++){
                soma[i] = (int *) malloc(c * sizeof(int));
                }
            if (soma == NULL){
                printf("memoria insuficiente");
            }
            else{
                for(i = 0; i < l; i++){
                    for(j = 0; j < c; j++){
                        soma[i][j] = mat1[i][j] + mat2[i][j]
                    }
                }
            }


        }
    }
    return 0;
}
