#include <stdio.h>

void f_sqr(int a, int b, int c)
{
    float delta = (b*b) - (4*a*c);
    float x1 = (-b + (sqrt(delta))/(2*a));
    float x2 = (-b - (sqrt(delta)))/(2*a);
    if (delta > 0)
    {
        printf("x1 = %.2f , x2 = %.2f", x1, x2);
    }
    else if (delta == 0)
    {
        printf("x1 = x2 = %.2f", x1);
    }
    else
    {
        printf("No real roots");
    }

}

int main()
{
    int a, b, c;
    printf("Enter a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);

    f_sqr(a, b, c);

    return 0;
}