#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"

#define BUFFER 256

FILE *arquivo;
FILE *arquivo_final;    

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

        else if(!strcmp(leitor, "RETIRA")){
            fscanf(arquivo, "%d", &codigo);
            l = RetiraListaProduto(l, codigo);
        }

        else if(!strcmp(leitor, "IMPRIME_LISTA")){
            ImprimeListaProdutos(l);
        }

        else if(!strcmp(leitor, "ATUALIZA_PRECO")){
            fscanf(arquivo, "%d", &codigo);
            fscanf(arquivo, "%f", &valor);
            l = AtualizaPrecoProduto(l, codigo, valor);            
        }

        else if(!strcmp(leitor, "VERIFICA_VALIDADE")){
            fscanf(arquivo, "%d", &data[0]);
            fscanf(arquivo, "%d", &data[1]);
            fscanf(arquivo, "%d", &data[2]);
            l = VerificaListaValidade(l, data[0], data[1], data[2]);
        }

        else if(!strcmp(leitor, "VERIFICA_LISTA")){
            fscanf(arquivo, "%d", &codigo);
            int isInList = VerificaListaProduto(l, codigo);
        }

        else if (!strcmp(leitor, "ORDENA_LISTA_VALIDADE")) {
            l = OrdenaListaVencimento(l);
        }

        else if (!strcmp(leitor, "ORDENA_LISTA_VALOR")) {
            l = OrdenaListaValor(l);
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