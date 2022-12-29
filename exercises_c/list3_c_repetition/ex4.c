#include<stdio.h>

int main()
{
    int number, l1, l2, area;
    printf("Enter the number of rectangles: ");
    scanf("%d", &number);

    for(int i = 1; i <= number; i++)
    {
        printf("Enter the length of the first side of rectangle %d: ", i);
        scanf("%d", &l1);
        printf("Enter the length of the second side of rectangle %d: ", i);
        scanf("%d", &l2);
        area = l1 * l2;
        printf("The area of the rectangle %d is %d\n", i, area);
    }

    return 0;
}