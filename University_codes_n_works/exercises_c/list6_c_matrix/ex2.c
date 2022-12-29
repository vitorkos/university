#include<stdio.h>

int f_bigger(int mat[][5]){
    int bigger = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 5; j++){
                if (mat[i][j] > bigger){
                    bigger = mat[i][j];
                }
                else{}
            }
        }
        return bigger;
}


int main()
{
    int mat[4][5];
    int bigger;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            printf("enter the value of the position [%d][%d]: ", i, j );
            scanf("%d", &mat[i][j]);
        }
    }

    bigger = f_bigger(mat);

    printf("the bigger value of the matrix is: %d", bigger);

    return 0;
}
