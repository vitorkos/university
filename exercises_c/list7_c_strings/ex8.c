#include<stdio.h>
#include<string.h>

int main()
{
    int count = 0;
    char str[100];
    printf("enter a string: ");
    fgets(str, 100, stdin);
    char c;
    printf("enter a character: ");
    scanf("%c", &c);

    for(int i = 0; str[i] != '\n'; i++){
        if(str[i] == c){
            count++;
        }
        else{}
    }

    printf("the number of times the character appears in the string is: %d" , count);

    return 0;
}