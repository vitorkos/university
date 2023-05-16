#include <stdio.h>
struct Person{
    float height;
    float weight;
    float bmi;
};
int main()
{
    int n;
    printf("Enter the number of people to have their BMI calculated: ");
    scanf("%d", &n);
    struct Person p[n];
    for(int i = 0; i < n; i++){
        printf("Enter the %d height: ", i);
        scanf("%f", &p[i].height);
        printf("Enter the %d height: ", i);
        scanf("%f", &p[i].weight);
        p[i].bmi = p[i].weight / (p[i].height * p[i].height);
    }
    for(int i = 0; i < n; i++){
        printf("%d - Height : %.2f - Weight : %.2f - BMI : %.2f", i, p[i].height, p[i].weight, p[i].bmi);
    }
    return 0;
}