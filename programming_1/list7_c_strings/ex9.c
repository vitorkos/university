#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

int main()
{
    char str[50], aux[50];
    int a, b;

    printf("enter a string: ");
    gets(str);
    b = strlen(str)-1;

    for( a = 0; str[a] != '\0' ;a++){        
        aux[b] = str[a];
        b--;
    }
    aux[a] = '\0';      
    strcpy(str, aux);
    

    if(strcmp(str, aux) == 0){
        printf("the string is a palindrome");
    }
    else{
        printf("the string is not a palindrome");
    }
    return 0;
}