#include<stdio.h>
#include<stdlib.h>
int main()
{

    int num, sucessor, antecessor;

    printf("\n Digite um número: ");
    scanf("%d", &num);

    sucessor = num + 1;
    antecessor = num - 1;

    printf("O número sucessor é: %d\n", sucessor);
    printf("O número antecessor é: %d\n", antecessor);
return 0;
}
