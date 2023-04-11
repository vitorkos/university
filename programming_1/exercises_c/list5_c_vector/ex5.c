#include<stdio.h>

int main()
{
    int n, i;
    float tax;
    printf("enter the number of employees: ");
    scanf("%d", &n);
    float vet[n];
    if(n > 50){
        printf("the number of employees must be less than 50");
    }
    else{
        for(i = 0; i < n; i++){
            printf("enter the salary of the %d employee: ", i);
            scanf("%f", &vet[i]);
        }
        for (i = 0; i < n; i++){
            if (vet[i] <= 1904){
                printf("the employee %f has no tax", vet[i]);
            }
            else if(vet[i] > 1904 && vet[i] <= 2827){
                tax =vet[i] * 7.5;
                printf("the employee %f has a tax of %f", vet[i], tax);
            }
            else if(vet[i] > 2827 && vet[i] <= 3751){
                tax =vet[i] * 15;
                printf("the employee %f has a tax of %f", vet[i], tax);
            }
            else if(vet[i] > 3751 && vet[i] <= 4665){
                tax =vet[i] * 22.5;
                printf("the employee %f has a tax of %f", vet[i], tax);
            }
            else if(vet[i] > 4665){
                tax =vet[i] * 27.5;
                printf("the employee %f has a tax of %f", vet[i], tax);
            }
        }


    }
    return 0;
}