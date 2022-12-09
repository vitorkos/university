#include<stdio.h>
#include<stdlib.h>

int main(){
    int cafe;
    cafe = 7;

    int valorpago;
    printf("\n insira o valor que voce ira pagar(somente em notas de 5): ");
    scanf("%d", &valorpago);

    int troco;
    troco = valorpago % cafe;

    printf("O troco perdido foi de %d", troco);

return 0;
}
