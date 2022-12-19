#include<stdio.h>
#include<string.h>

int f_qnt(char str1[100])
{
    int qnt = 0;
    for(int i = 0; str1[i] != '\n'; i++){
        if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' || str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U'  ){
            qnt++;
        }
        else{}
    }
    return qnt;
}

int main()
{
    char str1[100];
    printf("enter a string:");
    fgets(str1, 100, stdin);

    int qnt = f_qnt(str1);

    printf("the number of vowels is: %d" , qnt);

    return 0;
}