#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"

FILE *arquivo_final = NULL;

#define BUFFER 256

FILE *arquivo; 


void printElapsedTime(clock_t start, clock_t end) {
    double elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", elapsed_time);
}

//argc = quantidade de argumentos
//argv = argumentos

int main(int argc, char *argv[]){
    
    char leitor[20];

    if(argc != 3){
        puts("Quantidade de argumentos inválida!\n");
        return 1;
    }

    //Abre o arquivo de entrada
    
    arquivo = fopen(argv[1], "r");

    if(arquivo == NULL){
        puts("Falha ao abrir o arquivo de entrada!\n");
        perror(NULL);
        return 1;
    }
    arquivo_final = fopen(argv[2], "a");

    if(arquivo_final == NULL){
        puts("Falha ao abrir o arquivo de saída!\n");
        perror(NULL);
        return 1;
    }

    char nome[20];
    int codigo;
    float valor;
    int data[3];


    //Cria a lista
    Lista *l = CriaLista();

    clock_t start_time, end_time;

    while(fscanf(arquivo, "%s", leitor) != EOF){
        
        if(!strcmp(leitor, "PRODUTO")){

            fscanf(arquivo, "%s", nome);
            fscanf(arquivo, "%d", &codigo);
            fscanf(arquivo, "%f", &valor);
            fscanf(arquivo, "%d", &data[0]);
            fscanf(arquivo, "%d", &data[1]);
            fscanf(arquivo, "%d", &data[2]);

            Produto *p = CriaProduto(nome, codigo, valor, data);
            l = InsereListaProduto(l, p);
        }

        else if (!strcmp(leitor, "ORDENA_LISTA_VALOR")) {
            start_time = clock();
            for (int i = 0; i < 30; i++) {
                l = OrdenaListaValor(l);
                printf("Ordenação %d:\n", i + 1);
                end_time = clock();
                printElapsedTime(start_time, end_time);
                start_time = end_time;
            }
        }

        else if (!strcmp(leitor, "FIM")) {
        break;
        }

        else {
            printf("Comando não reconhecido: %s\n", leitor);
        }
    }

    fclose(arquivo);
    fclose(arquivo_final);

    return 0;
}