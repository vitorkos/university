/*
Ponteiros e referencia são sinonimos
A memoria RAM de um pc é representada por um conjunto de bytes
A sequencia que um byte ocura na sequencia é chamado de ENDEREÇO
Cada variavel na memoria possui um endereço que é dado pelo operador &
Assim, de I for uma variavel, seu endereço é dado por &I

Um ponteiro é um tipo especial de variavel que armazena um endereço
Um ponteiro pode ter o valor de NULL, um endereço invalido
Se um ponteiro P armazena o endereço de uma variável I, falamos que "P aponta para I" ou "P é o endereço de I" ou que P é uma referencia à I
Se um ponteiro P tem valor diferente de NULL então *P é o VALOR da variavel apontada por P
Assim, se I é uma variavel e P vale &I então "*P" é o mesmo que "I"

Sua declaração de da: TIPO DO PONTEIRO *NOME DO PONTEIRO;

int *p = NULL --> aponta um valor de memoria inexistente

int *p, x;
p = &x; --> aponta um valor de memoria existente

* --> acessa o conteudo da variavel daquele endereço apontado
& --> aponta somente o endereço da variavel referenciada

*/


#include<stdio.h>

int main()
{

    //exemplos de ponteiros

    int a;

    int *p;
    p =  &a;

    printf("insira o valor da variavel a: ");
    scanf("%d", &a);

    printf("o valor de a é %d", *p);

    return 0;
}

//caso no print do valor de A, o ponteiro P não possuisse *, seria printado somente o endereço de A
