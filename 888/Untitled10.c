#include<stdio.h>

char estacao(int dia, int mes, char a)
{
    if (mes < 9 && mes > 12 ){
        if ((mes == 9 && dia <= 21) || (mes == 12 && dia >= 20)){
            a = "primavera";
            return a;
        }
    }
    if (mes < 12 && mes > 3 ){
        if ((mes == 12 && dia <= 21) || (mes == 3 && dia >= 20)){
            a = "verão";
            return a;
        }
    }
    if (mes < 3 && mes > 6 ){
        if ((mes == 3 && dia <= 21) || (mes == 6 && dia >= 20)){
            a = "outono";
            return a;
        }
    }
    if (mes < 6 && mes > 9 ){
        if ((mes == 6 && dia <= 21) || (mes == 9 && dia >= 20)){
            a = "inverno";
            return a;
        }
    }
}


int main()
{
    int dia, mes;
    char b, a;
    char est;

    printf("insira um dia e um mes(1 a 12): ");
    scanf("%d%d", &dia, &mes);

    b = estacao(dia, mes, a);

    printf("a data pertence a estacao %c", b);

    return 0;
}
