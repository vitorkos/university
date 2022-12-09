#include<stdio.h>

int main()
{
    int codigo;
    float salario;
    float a, b, c, d;
    printf("insira o codigo do cargo: ");
    scanf("%d", &codigo);
    printf("insira o valor do salario: ");
    scanf("%f", &salario);

    a = (salario * 0.10) ;
    b = (salario * 0.07) ;
    c = (salario * 0.12) ;
    d = (salario * 0.11) ;

    if (codigo == 1){
        printf("o valor do reajuste é de %f e o salario fica em %f",salario, a + salario);
    }

    else if (codigo == 2){
        printf("o valor do reajuste é de %f e o salario fica em %f", salario, b + salario);
    }

    else if (codigo == 3){
        printf("o valor do reajuste é de %f e o salario fica em %f", salario, c + salario);
    }

    else if (codigo == 4){
        printf("o valor do reajuste é de %f e o salario fica em %f", salario, d + salario);
    }
    return 0;

}
