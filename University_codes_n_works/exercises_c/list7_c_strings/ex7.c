#include<stdio.h>
#include<string.h>

int main()
{
    int i, aux = 0;
    char str[100];
    printf("enter a string: ");
    fgets(str, 100, stdin);
    int len = strlen(str);

    for(i = 0; i != len; i++){
        printf("%c\n", str[i]);
    }

    return 0;
}