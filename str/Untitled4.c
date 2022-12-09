#include<stdio.h>
#include<string.h>

/*Faca um programa que leia uma string informada pelo usuario e, em seguida, implemente
uma funcao que contabilize a quantidade de espacos em branco existente na string lida.*/

int espaco(char frase[500], int tamanho, int count)
{
    for(int i = 0; i != tamanho; i++){
            if(frase[i] == ' '){
                count++;
            }
            else{}
    }
    return count;
}

int main()
{
    char frase[500];
    int count = 0;
    printf("insira uma frase: ");
    fgets(frase, 500, stdin);
    int tamanho = strlen(frase) - 1;

    int funcao = espaco(frase, tamanho, count);

    printf("o numero de espacos eh: %d", funcao );

    return 0;
}
