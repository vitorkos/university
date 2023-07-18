#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;
    char linha[100];
    char palavra[100];

    arq = fopen("./entrada.txt", "r");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    //PERCORRE LINHA POR LINHA
    while(fgets(linha, 100, arq) != NULL){
        //VERIFICA A PRIMEIRA PALAVRA DA LINHA
        if(sscanf(linha, "%s", palavra) == 1){
            //VERIFICA QUAL A PRIMEIRA PALAVRA DA LINHA
                if (strcmp(palavra, "PRODUTO") == 0){
            }
            else if (strcmp(palavra, "RETIRA") == 0){
            }
            else if (strcmp(palavra, "IMPRIME_LISTA") == 0){
            }
            else if (strcmp(palavra, "ATUALIZA_PRECO") == 0){
            }
            else if (strcmp(palavra, "VERIFICA_VALIDADE") == 0){
            }
            else if (strcmp(palavra, "VERIFICA_LISTA") == 0){
            }
            else if (strcmp(palavra, "ORDENA_LISTA_VALIDADE") == 0){
            }
            else if (strcmp(palavra, "IMPRIME_LISTA") == 0){
            }
            else if (strcmp(palavra, "ORDENA_LISTA_VALOR") == 0){
            }
            
        }
    }
    fclose(arq);


    return 0;
}