#include<stdio.h>
#include<string.h>

/*Faca um programa que leia duas strings quaisquer e mostre se as duas sao iguais ou
diferentes no conteudo e se possuem o mesmo tamanho. Lembre-se que as strings podem
conter letras maiusculas e/ou minusculas.*/

int main()
{
    char str1[100];
    char str2[100];
    printf("enter a string:");
    fgets(str1, 100, stdin);
    printf("enter another string:");
    fgets(str2, 100, stdin);

    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    if(len1 == len2){
        printf("the strings have the same length");
    }
    else{
        printf("the strings have different lengths");
    }

    for(int i = 0; i != len1; i++){
        if(str1[i] == str2[i]){
            printf("the strings are equal");
        }
        else{
            printf("the strings are different");
        }
    }
    return 0;
}