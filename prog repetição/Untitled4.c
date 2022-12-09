#include<stdio.h>

int main()
{
    int n;
    int l1, l2;
    int area;
    int count = 0;

    printf("insira a quantidade de retangulos: ");
    scanf("%d", &n);

    while(count <= n){
        printf("insira os valores das laterais: ");
        scanf("%d%d", &l1,&l2);
        area = l1 * l2;
        printf("area do retangulo %d é %d\n", count, area);
        count++;

    }
    return 0;
}
