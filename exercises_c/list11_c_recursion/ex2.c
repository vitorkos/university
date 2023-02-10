#include <stdio.h>

int f_sum(int vet[], int n)
{
    if (vet[] > n){
        return 0;
    }
    else{
        return f_sum(vet[n]);
    }
}

int main()
{
    int n = 10;
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int result = f_sum(vet, n);
    printf("%d\n", result);

    return 0;
}