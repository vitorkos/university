#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x1, x2;
    printf("insert a, b and c: ");
    scanf("%f%f%f", &a, &b, &c);

    float delta = (b * b) - (4 * a * c);

    if(delta < 0){
        printf("theres no real square for the function");
    }
    else{
        x1 = (-b + sqrt(delta))/ (2 * a);
        x2 = (-b - sqrt(delta))/ (2 * a);
        printf("the squares of the function are %.2f and %.2f", x1, x2);
    }
}