#include<stdio.h>

int main()
{
    int n1, n2, n3;
    printf("insira 3 numeros: \n");
    scanf("%d%d%d", &n1, &n2, &n3);

    if (n1 == n2 && n2 == n3){
        printf("1");
    }
    else if(n1 == n2 || n1 == n3 || n3 == n2){
        printf("3");
    }
    else{
        printf("2");
    }
    return 0;
}
