#include <stdio.h>

int main()
{
    float x, y;
    int code;
    printf("enter X and Y: ");
    scanf("%f%f", &x, &y);

    printf("1 - MEDIUM\n2 - DIFERENCE\n3 - PRODUCT\n 4 - DIVISION: \n");
    scanf("%d", &code);

    if (code == 1){
        printf("%.2f", (x + y) / 2);
    }
    else if (code == 2){
        printf("%.2f", x - y);
    }
    else if (code == 3){
        printf("%.2f", x * y);
    }
    else if (code == 4){
        printf("%.2f", x / y);
    }

    return 0;
}