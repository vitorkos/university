#include <stdio.h>

int main()
{
    int side1, side2, side3;
    printf("insert the value of the sides of the triangle: \n");
    printf("side 1: ");
    scanf("%d", &side1);
    printf("side 2: ");
    scanf("%d", &side2);
    printf("side 3: ");
    scanf("%d", &side3);

    if (side1 == side2 == side3){
        printf("this is a equilateral triangle");
    }
    else if ((side1 == side2)||(side2 == side3)||(side3 == side1)){
        printf("this is a isosceles triangle");
    }
    else if (side1 != side2 != side3){
        printf("this is a scalene triangle");
    }

    return 0;    
}