#include<stdio.h>

void atribui(int mat[][3])
{
    for (int i = 0; i != 3; i++){
        for (int j = 0; j != 3; j++){
            printf("insira o valor da posicao [%d][%d] do vetor: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int main()
{
    int mat[3][3];

    atribui(mat);

    return 0;
}
//função com uma matriz.
