#include <stdio.h>

int main()
{
    float n1, n2, n3;
    printf("insert n1, n2 and n3: ");
    scanf("%f%f%f", &n1, &n2, &n3);

    float average = (n1 + n2 + n3) / 3;

    if (n1 > average && n2 > average && n3 > average){
        printf("the number of variables above the mean is 3");
    }
    else if((n1 > average && n2 > average)||(n2 > average && n3 > average)||(n1 > average && n3 > average)){
        printf("the number of variables above the mean is 2");
    }
    else{
        printf("only one number is above the mean");
    }

    return 0;
}