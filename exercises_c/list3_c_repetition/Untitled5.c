#include<stdio.h>

int main()
{
    int x, y;
    printf("insira dois valores, um de inicio outro de fim: ");
    scanf("%d%d", &x, &y);

    while(x < y){
        if (x % 5 == 2){
            printf("%d", x);
        }
        else if(x % 5 == 3){
            printf("%d", x);
        }
        x++;
    }
    return 0;
}
