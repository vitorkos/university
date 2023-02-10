#include<stdio.h>
#include<string.h>

/*Faca um programa para criptografar uma string qualquer informada pelo usuario, substituindo
cada letra da string pela letra do alfabeto em sua respectiva posicao, mas de tŕas para frente.
Por exemplo, se a string digitada for adoro programar em c a sa ida deve ser zwlil kiltiznzi
vn x. */

int main()
{
    char alfa[27] = "abcdefghijklmnopqrstuvwxyz";//26 letras
    char alfa2[27] = "zyxwvutsrqponmlkjihgfedcba";
    int j = 0;

    char str[500];
    printf("enter a string:");
    fgets(str, 500, stdin);
    int len = strlen(str) - 1;

    for(int i = 0; i != len; i++){
        if(str[i] == alfa[j]){
            str[i] = alfa2[j];
        }
        else{
            j++;
        }
    }

    printf("the string in reverse is: %s " , str);

    return 0;
}
