#include<stdio.h>
#include<string.h>

/*Faca um programa que leia uma string informada pelo usuario e, em seguida, implemente
uma funcao que contabilize a quantidade de espacos em branco existente na string lida.*/

int f_space(char str[500], int len)
{
    int count = 0;
    for(int i = 0; i != len; i++){
            if(str[i] == ' '){
                count++;
            }
            else{}
    }
    return count;
}

int main()
{
    char str[500];
    printf("enter a string:");
    fgets(str, 500, stdin);
    int len = strlen(str) - 1;

    int space = f_space(str, len);

    printf("o numero de espacos eh: %d", space);

    return 0;
}