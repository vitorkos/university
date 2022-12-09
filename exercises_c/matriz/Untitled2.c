#include<stdio.h>

int lemaior(int matriz[][5], int i, int j, int maior){
        for(i = 0; i < 4; i++){
            for(j = 0; j < 5; j++){
                if (matriz[i][j] > maior){
                    maior = matriz[i][j];
                }
                else{}
            }
        }
        return maior;
}


int main()
{
    int i, j;
    int matriz[4][5];
    int maior1;
    int maior = 0;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            printf("insira o valor da matriz [%d %d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    maior1 = lemaior(matriz, i, j, maior);

    printf("o maior valor da matriz eh %d", maior1);

    return 0;
}
