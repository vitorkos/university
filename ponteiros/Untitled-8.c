//certp
#include<stdio.h>

int main()
{
    int x = 5 , y = 10;
    int *p1 = &x ;
    int *p2 = &y ;

    int a = (*p1 += *p2);

    printf("%d", a);
    return 0;
}
//a - errado, pois usa o endereço apontado por p1, que é diferente do de p2
//b - errado, pois usa os endenreços
//c certo, pois usa o conteudo das variaveis indicados pelos seus endereços nos ponteiros
//d - errado - usa endereço
//e - errado - usa o endereço;
