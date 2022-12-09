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

    char frase[500];
    printf("insira uma frase: ");
    fgets(frase, 500, stdin);
    int len = strlen(frase) - 1;

    for(int i = 0; i != len; i++){
        if(frase[i] == alfa[j]){
            frase[i] = alfa2[j];
        }
        else{
            j++;
        }
    }

    printf(" a frase invertida eh %s", frase);

    return 0;
}
