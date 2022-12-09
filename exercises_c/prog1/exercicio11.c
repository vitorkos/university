#include<stdio.h>

int main()
{
    int idade, altura;
    printf("insira a sua idade e a sua  altura(cm): ");
    scanf("%d%d", &idade, &altura);

    if (idade >= 16 && altura >= 170){
        printf("voce pode ir em todos os brinquedos");
    }
    else if (idade >= 14 && idade < 16 && altura >= 140){
        printf("voce pode ir em 2 brinquedos");
    }
    else if( idade >=12 && idade < 14 && altura >= 150 ){
        printf("voce pode ir em somente um brinquedo");
    }
    return 0;
}
