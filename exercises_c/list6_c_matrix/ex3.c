#include<stdio.h>

int main()
{
    int mat[5][3], div7[15];
    int p = 0, n = 0,  i, j;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            printf("enter the value of the position [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
            if(mat[i][j] % 7 == 0){
                div7[p] = mat[i][j];
                n++;
            }

            p++;
        }
    }    

    


    printf("the numbers divisible by 7 are: ");
    for(i = 0; i < n; i++){
        printf("%d - ", div7[i]);
    }

    return 0;
}