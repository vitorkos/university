#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m, n, x, y;
    printf("\n apresente os valores de m, n, x e y\n ");
    scanf("%d",&m);
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);

    int diferenca1, diferenca2;
    diferenca1 = m - n;
    diferenca2 = x - y;

    printf("\n a diferença de entre m e n é de: %d", diferenca1);
    printf("\n a diferença entre x e y é de : %d", diferenca2);

return 0;
}
