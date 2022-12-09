//roda
#include<stdio.h>
#include<math.h>

int main()
{
    float x1, x2, y1, y2;

    printf("insira as coordenadas de x e y\n\n");

    printf("X1: ");
    scanf("%f", &x1);

    printf("X2: ");
    scanf("%f", &x2);

    printf("Y1: ");
    scanf("%f", &y1);

    printf("Y: ");
    scanf("%f", &y2);

    float sub1 = (x1 - x2) * (x1 - x2);
    float sub2 = (y1 - y2) * (y1 - y2);

    float soma = sub1 + sub2;

    float resultado = sqrt(soma);

    printf("a distancia entre dois pontos é de %f", resultado);




    return 0;
}
