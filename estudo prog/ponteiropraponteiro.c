//EXEMPLO ::: PONTEIRO PRA PONTEIRO

#include<stdio.h>
int main()
{
    int a = 5, *b, **c;
    b = &a;
    c = &b;
    printf("%d\n%d\n%d\n", a, *b, *(*c));
    return 0;
}
