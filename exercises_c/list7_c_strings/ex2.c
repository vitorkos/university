#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    printf("enter a string: ");
    fgets(str, 100, stdin);

    for(int i = 0; str[i] != '\n'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            str[i] = '*';
        }
        else{}

    }

    printf("the string with vowels replaced by * is: %s " , str);

    return 0;
}
