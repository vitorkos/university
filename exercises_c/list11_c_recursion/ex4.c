#include <stdio.h>

int multiply(int a, int b)
{
    if (b == 1) {
        return a;
    }
    return a + multiply(a, b-1);
}

int main() {

    int num1, num2;
    printf("Enter a multiplied and a multiplier: ");
    scanf("%d%d", &num1, &num2);

    int result = multiply(num1, num2);
    printf("The result of %d x %d is %d\n", num1, num2, result);

    return 0;
}