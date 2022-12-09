#include<stdio.h>

int main()
{
    int div;
    int dividendo = 1;
    int s;
    int soma = 0;

    for(div = 1; div <= 50; div++){
        printf("(%d / %d ) + ", dividendo, div);
        s  = dividendo / div;
        soma = soma + s;
        dividendo = dividendo + 2;
    }
    printf("a soma entre as divisões é %d", soma);

    return 0;
}
