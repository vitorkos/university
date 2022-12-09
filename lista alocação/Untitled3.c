#include<stdio.h>
#include<stdlib.h>

int main()
{
    int l, c, i, j, k, conta = 0;
    int **mat;
    int *vet;

    printf("insira o numero de linhas: ")
    scanf("%d", &l);
    printf("insira o numero de linhas: ")
    scanf("%d", &l);

    //numero de linhas
    mat = (int **) malloc(l * sizeof(int));

    //cada LINHAS recebe um vetor com o numero de COLUNAS
    for(i = 0; i < l; i++){
        mat[i] = (int *) malloc(c * sizeof(int));
    }

    //atribui
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("insira o valor de [%d][%d]", i, j)
            scanf("%d", mat[i][j]);
        }
    }
    //conta a quantidade de impares multiplos de 7
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] % 2 != 0 && mat[i][j] % 7 = 0){
                conta++;
            }
            else{}
        }
    }
    //aloca o tamanho do vetor
    vet = (int *) malloc(conta * sizeof(int));
    //atribui os valores ao vetor
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] % 2 != 0 && mat[i][j] % 7 = 0){
                for(k = 0; k < conta; k++){
                    vet[k] = mat[i][j];
                }
            }
            else{}
        }
    }
    return 0;
}
