#include<stdio.h>
#include<math.h>

float f_delta(float a, float b, float c)
{
    float delta;
    delta = (b*b) - (4*a*c);
    return delta;
}
float f_x1(float a, float b, float delta)
{
    float x1;
    x1 = (-b + (sqrt(delta))/(2*a));
    return x1;
}
float f_x2(float a, float b, float delta)
{
    float x2;
    x2 = (-b - sqrt(delta))/(2*a);
    return x2;
}

int main()
{
    float a, b, c, delta, x1, x2;
    printf("Enter a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);

    delta = f_delta(a, b, c);
    x1 = f_x1(a, b, delta);
    x2 = f_x2(a, b, delta);

    if(delta > 0)
    {
        printf("x1 = %.2f , x2 = %.2f", x1, x2);
    }
    else if(delta == 0)
    {
        printf("x1 = x2 = %.2f", x1);
    }
    else
    {
        printf("No real roots");
    }
    return 0;
}