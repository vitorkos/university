#include <stdio.h>

int main()
{
    int n1, n2, n3;
    printf("enter the numbers of n1, n2 and n3: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    printf("if all numbers are the same, will be printed  1\nifall number are difent, 2\nand if only two number are the same, 3:\n ");

    if (n1 == n2 == n3){
        printf("1");
    }
    else if((n1 == n2)||(n1 == n3)||(n2 == n3)){
        printf("3");
    }
    else if(n1 != n2 != n3){
        printf("2");
    }

    return 0;
}