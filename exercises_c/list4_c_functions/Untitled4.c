#include<stdio.h>

int potencia(int x, int y){
    int pot = 1;
    int i = 0;
    while ( i != y){
        pot = pot * x;
        i = i + 1;
    }
    return pot;
}

int main(){
    int x, y, a;

    printf("insira dois valores: ");
    scanf("%d%d", &x, &y);

    a = potencia(x, y);
    printf("x elevado a y � %d", a);

    return 0;
}