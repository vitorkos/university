#include<stdio.h>

int main()
{
    int multiplicando, multiplicador, resultado;

    for(multiplicador = 1; multiplicador <= 10; multiplicador++){
        printf("tabuada do numero %d\n", multiplicador);
        for(multiplicando = 1; multiplicando <= 10; multiplicando++){
            resultado = multiplicador * multiplicando;
            printf("%d x %d = %d\n",multiplicador, multiplicando, resultado);
        }
    }
    return 0;
}
