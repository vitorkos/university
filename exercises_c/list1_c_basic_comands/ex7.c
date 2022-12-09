#include <stdio.h>

int main()
{
    float a, b, c, a1, a2, a3, a4;
    printf("insert the values of a, b and c: ");
    scanf("%f%f%f", &a, &b, &c);

    a1 = (a * b) / c;
    a2 = (a * a) + b + (5 * c);
    a3 = (a * b* c) + b + ((c / 3) * 5) - 1;
    a4 = ((a * b * c) * (a * b * c) * (a * b * c)) / 2;

    printf("(a * b) / c = %.0f\n(a * a) + b + (5 * c) = %.0f\n(a * b* c) + b + ((c / 3) * 5) - 1 = %.0f\n((a * b * c) * (a * b * c) * (a * b * c)) / 2 = %.0f", a1, a2, a3, a4);

    return 0;
}