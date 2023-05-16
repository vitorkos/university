#include <stdio.h> 
#include <stdlib.h>

int main(){
    int n, bigger = 0, smaller = 0;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int **matrix;
    matrix = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Enter the element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] > bigger){
                bigger = matrix[i][j];
            }
            if(matrix[i][j] < smaller){
                smaller = matrix[i][j];
            }
        }
    }
    printf("The biggest element is %d and the smallest is %d\n", bigger, smaller);
    for(int i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}