#include <stdio.h>
#include <stdlib.h>

int f_bigger(int n, int array[])
{
    if (n == 1){
        return array[0];
    }
    bigger = f_bigger(array, n - 1)
    if (array[n - 1] > m){
        return array[n - 1];
    }
    return bigger;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];

    for(int i = 0; i < n; i++){
        printf("Enter array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    int result = f_bigger(n, array);

    printf("The bigger number in array is %d\n", result);
}