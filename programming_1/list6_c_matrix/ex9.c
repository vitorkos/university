#include <stdio.h>

int main()
{
    int mat[5][3];
    int vet[5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            printf("enter the value of mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    int sum = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            sum += mat[i][j];
        }
        vet[i] = sum;
        sum = 0;
    }

    for(int i = 0; i < 5; i++){
        printf("the sum of the line %d is %d " , i, vet[i]);
    }

    return 0;

}