#include<stdio.h>
#include<stdlib.h>

int main()
{
    int km;
    printf("\n Quantos kilometros foram andados? \n");
    scanf("%d", &km);

    int litros;
    printf("\n Quantos litros foram gastos? \n");
    scanf("%d", &litros);

    int media;
    media = km / litros;

    printf("A media de uso de combustivel de litro por km é de %d", media);

return 0;
}
