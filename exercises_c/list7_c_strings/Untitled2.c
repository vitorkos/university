#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    printf("insira uma string: ");
    fgets(str, 100, stdin);

    for(int i = 0; str[i] != '\n'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            str[i] = '*';
        }
        else{}

    }

    printf("%s", str);

    return 0;

}
