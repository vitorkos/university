#include <stdio.h>
#include <stdlib.h>

struct Pressure{
    double weight;
    double area;
    double pressure;
};
int main(){
    int n;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    struct Pressure *p;
    p = (struct Pressure *)calloc(n, sizeof(struct Pressure));

    for(int i = 0; i < n; i++){
        printf("Enter the weight of object %d: ", i + 1);
        scanf("%lf", &p[i].weight);
        printf("Enter the area of object %d: ", i + 1);
        scanf("%lf", &p[i].area);
        p[i].pressure = p[i].weight / p[i].area;
    }
    for(int i = 0; i < n; i++){
        printf("The pressure of object %d is %lf\n", i + 1, p[i].pressure);
    }
    free(p);
    return 0;
}