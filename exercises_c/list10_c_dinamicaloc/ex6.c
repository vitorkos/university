#include <stdio.h>
#include <stdlib.h>

int **f_insert(int n)
{
     int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)(malloc(n * sizeof(int)));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                mat[i][j] = 1;
            }
            else {
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}

int main()
{
    int n;

    printf("enter the number of the square matrix:");
    scanf("%d", &n);

    int **mat = f_insert(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}