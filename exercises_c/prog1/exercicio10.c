#include<stdio.h>

int main()
{
    int num1, num2, num3;
    printf("insira 3 valores : ");
    scanf("%d%d%d", &num1,&num2,&num3);

    if (num1 < num2 && num2 < num3 ){
        if(num3 < num2){
            printf("%d%d%d", num1, num3, num2);
        }
        else{
            printf("%d%d%d", num1, num2, num3);
        }
    }
    else if(num2 < num1 && num1 < num3){
        if (num3 < num1){
            printf("%d%d%d",num2, num3, num1);
        }
        else{
            printf("%d%d%d",num2, num1, num3);
        }
    }
    else if (num3< num1 && num1 < num2){
        if (num2 < num1){
            printf("%d%d%d",num3, num2, num1);
        }
        else{
            printf("%d%d%d",num3, num1, num2);
        }
    }
    return 0;
}
