#include<stdio.h>
#include<stdlib.h>

void atri(int **mat, int linha, int coluna)
{
    int i, j;

    mat = (int **)malloc (linha * sizeof(int));
    for(i = 0; i < linha; i++){
        mat[i] = (int *) malloc (coluna * sizeof(int));
    }

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("insira o valor de [i][j] da matriz");
        }
    }
}

int buscanumero(int numero, int **mat, int linha, int coluna)
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
    int l, c, **matriz;

    printf("insira o numero de linhas: ");
    scanf("%d", &l);
    printf("insira o numero de colunas: ");
    scanf("%d", &c);

    atri(matriz, l, c);

    int n;
    printf("insira o numero a ser procurado: ");
    scanf("%d", &n);

    int busca = buscanumero(n, matriz, l, c);

    printf("%d", busca);

    return 0;
}
