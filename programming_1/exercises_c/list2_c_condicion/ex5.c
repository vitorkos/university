#include <stdio.h>

int main()
{
    float km;
    char ca;

    printf("enter past mileage: ");
    scanf("%f", &km);
    printf("enter the category:a, b or c: ");
    scanf("%s", &ca);

    if(ca == 'a'){
        printf("15KM/liter = %.2f", km / 15);
    }
    else if(ca == 'b'){
        printf("12KM/liter = %.2f", km / 12);
    }
    else if(ca == 'c'){
        printf("10KM/liter = %.2f", km / 10);
    }

    return 0;
}