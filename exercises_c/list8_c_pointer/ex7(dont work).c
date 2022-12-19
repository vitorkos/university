//arrumar

#include<stdio.h>

void matrizs(int *mat)
{
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("insira o valor de [%d][%d]", i, j);
            scanf("%d", mat[i][j]);
        }
    }
}

int numero(int *mat)
{
    int n;
    int ncount = 0;
    printf("insira o numero a ser contado: ");
    scanf("%d", &n);

    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; i < 4; j++){
            if(mat[i][j] == n){
                ncount++
            }
            else{}
        }
    }

    return ncount;
}

int main()
{
    int matriz[4][4];
    int *mat = &matriz[0][0];
    matrizs(mat);

    int numeroc;
    numeroc = numero(mat);

    printf("o numero se repete %d", numeroc);

    return 0;

}