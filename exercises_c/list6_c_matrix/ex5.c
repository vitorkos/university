#include <stdio.h>

int main()
{
    int mat[5][5];
    for(int i = 0; i < 5; i++){
        for (int j = 0; j< 5; j++){
            printf("enter the value of the position [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    int sum = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (i == j){
                sum += mat[i][j];
            }
        }
    }
    float avg = sum / 5;

    printf("the sum of the elements above the diagonal is: %d", sum);

    return 0;
}