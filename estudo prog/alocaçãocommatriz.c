/*
Em certas areas cientificas, é muito comum o uso e aplicação de MATRIZES
E em situações como essa, é ideal alocar uma memoria suficiente para os dados, sem amis nem menos

Para alocar memoria para uma matriz, usamos o conceito de PONTEIRO PARA PONTEIRO
Uma variavel ponteiro está alocada na memoria como qualquer outra
Portanto, podemos criar um ponteiro que contem o endereço de memoria de um outro ponteiro

TIPO **nome_ponteiro;

EXEMPLO ::: PONTEIRO PRA PONTEIRO

#include<stdio.h>
int main()
{
    int a = 5, *b, **c;
    b = &a;
    c = &b
    printf(%d\n%d\n%d\n, a, *b, *(*c));
    return 0;
}
VAI SER PRINTADO O 5 NAS TRÊS VEZES

Sabemos que um ponteiro pode ser usado para referenciar um
vetor alocado dinamicamente:

int *p;
p = (int *)malloc(5 * sizeof(int);

A mesma coisa acontece com um ponteiro pra ponteiro, so que neste
caso o vetor alocado é de ponteiros;

int **p;
p = (int *)malloc(5 * sizeof(int *);

Como cada posição do vetor  e um ponteiro para inteiro, podemos
associar cada posição dinamicamente com um vetor de inteiros;

int **p;
int i;
p = (int *) malloc(3 * sizeof(int))

for(i = 0; i < 5; i++){
    p[i] = (int *)malloc(3 * sizeof(int))
}


DE MANEIRA ESUMIDA ::: PARA CRIAR MATRIZES DINAMICAMENTE:::

CRIE UM PONTEIRO PRA UM PONTEIRO
ASSOCIE UM VETOR DE PONTEIROS DINAMICAMENTE COME SSE PONTEIRO DE PONTEIROS
O TAMANHO DESSE VETOR É O NUMERO DE LINHAS DA MATRIZ
CADA POSIÇÃO DO VETOR SERÁ ASSOCIADO COM UM OUTRO VETOR DO TIPO
CADA UM DESTES VETORES É UMA LINHA DA MATRIZ

*/

//exemplo alocação para uma matriz 4X3

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **p, i, j;
    //aloca um array de ponteiros, um para cada linha
    p = (int **) malloc(4 * sizeof(int *));
    //cada um dos ponteiros recebera um array de inteiros
    for(i = 0; i< 4; i++){
        p[i] = (int *) malloc(3 * sizeof(int));
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &p[i][j]);
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            printf("%d", p[i][j]);
        }
    //desalocando memoria usada
    for(i =0; i < 4; i++){
        free(p[i]);
        }
    }
    free(p);

    return 0;
}
