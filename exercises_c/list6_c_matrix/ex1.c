#include<stdio.h>

int main()
{
    int r, c, i, j;
    printf("enter the number of rows: (between 2 and 15)");
    scanf("%d", &r);
    printf("enter the number of columns: (between 3 and 20))");
    scanf("%d", &c);
    int mat[r][c];

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("enter the value of the position [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    int sumpair = 0;
    int sumodd = 0;

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] % 2 == 0){
                sumpair += mat[i][j];
            }
            else{
                sumodd += mat[i][j];
            }
        }
    }

    printf("the sum of the pair numbers is: %d", sumpair);
    printf("the sum of the odd numbers is: %d", sumodd);

    return 0;
}
