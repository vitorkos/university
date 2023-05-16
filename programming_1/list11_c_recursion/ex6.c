#include <stdio.h>

int f_sum(int n, int array[])
{
    if (n == 0){
        return 0;
    }
    
    return array[n - 1] + f_sum(n - 1, array);
}

void main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++){
        printf("Enter array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    int c_funcion = f_sum(n, array);
    printf("The sum between the array positions is %d\n", c_funcion);
}