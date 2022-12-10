#include <stdio.h>

int main()
{
    int a, b, c;
    printf("enter a, b and c: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a >= b >= c){
        printf("%d, %d, %d", a, b, c);
    }
    else if (b >= a >= c){
        printf("%d, %d, %d", b, a, c);
    }
    else if (b >= c >= a){
        printf("%d, %d, %d", b, c, a);
    }
    else if (c >= b >= a){
        printf("%d, %d, %d", c, b, a);
    }
    else{
        printf("%d, %d, %d", c, a, b);
    }

    return 0;
}