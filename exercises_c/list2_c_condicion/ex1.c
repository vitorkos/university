#include <stdio.h>

int main()
{
    int n1, n2, n3;
    printf("insert the values of n1, n2 and n3: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    if (n1 > n2 && n1 > n3){
        printf("the number n1 is the bigger");
    }
    else if(n2 > n1 && n2 > n3){
        printf("the number n2 is the bigger");
    }
    else{
        printf("the number n3 is the bigger");
    }

    return 0;
}