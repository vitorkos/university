#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, maxdistindex = 0;
    double *weight, avg, sum = 0, maxdist = 0;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    weight = (double *)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        printf("Enter the weight of person %d: ", i + 1);
        scanf("%lf", &weight[i]);
        sum += weight[i];
    }
    avg = sum / n;
    for(int i = 0; i < n; i++){
        if(fabs(weight[i] - avg) > maxdist){
            maxdist = fabs(weight[i] - avg);
            maxdistindex = i;
        }
    }
    printf("The person with the most different weight is person %d\n", maxdistindex + 1);
    free(weight);
    return 0;
}