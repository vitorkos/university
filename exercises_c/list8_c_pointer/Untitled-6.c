//arrumar

#include<stdio.h>
#include<string.h>
#include<assert.h>

char inverso(char *str)
{
    char str2[100];
    int i = 0;
    int j;
    j = strlen(str) - 1;
    
    while(i < j){
        str2 = str[i];
        str[i] = str[j];
        str[j] = str2;
        i++;
        j--;

    }

return str2[100];

}

int main()
{
    char string[100]
    printf("insira uma frase: ");
    fgets(string, 100, stdin);
    char *str;
    str = &string;


}