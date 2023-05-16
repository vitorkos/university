#include <stdio.h>
struct Circle 
{
    float radius;
    float circunference;
    float area;
};
int main()
{
    int n;
    printf("Enter the number of circles to have the area and perimeter calculated");
    scanf("%d", &n);
    struct Circle c[n];
    for(int i = 0; i < n; i++){
        printf("Enter the radius of circle %d: ", i);
        scanf("%f", &c[i].radius);
        c[i].circunference = 2 * 3.14 * c[i].radius;
        c[i].area = 3.14 * (c[i].radius * c[i].radius);
    }
    for(int i = 0; i < n; i++){
        printf("%d - Radius : %f - Circunference : %f - Area : %f", i, c[i].radius, c[i].circunference, c[i].area);
    }
    return 0;
}