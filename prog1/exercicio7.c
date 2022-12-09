#include<stdio.h>

int main()
{
    int codigo, quant;
    float a, b, c, d;
    printf("insira o codigo do produto: ");
    scanf("%d", &codigo);
    printf("insira a quantidade: ");
    scanf("%d", &quant);

    a = 5.30 * quant;
    b = 6.00 * quant;
    c = 3.20 * quant;
    d = 2.50 * quant;

    if (codigo == 1){
        if(a >= 15){
            printf("o valor da compra com desconto vai ser de %f", a * 0.15);
        }
        else{
            printf("o valor da compra sem o desconto vai ser de %f",a);
        }
    }



    else if (codigo == 2){
        if(a >= 15){
            printf("o valor da compra com desconto vai ser de %f", b * 0.15);
        }
        else{
            printf("o valor da compra sem o desconto vai ser de %f",b);
        }
    }



    else if (codigo == 3){
        if(c >= 15){
            printf("o valor da compra com desconto vai ser de %f", c * 0.15);
        }
        else{
            printf("o valor da compra sem o desconto vai ser de %f",c);
        }
    }



    else if (codigo == 4){
        if(d >= 15){
            printf("o valor da compra com desconto vai ser de %f", d * 0.15);
        }
        else{
            printf("o valor da compra sem o desconto vai ser de %f",d);
        }
    }
    return 0;

}
