#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <tamanho_lista> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    int tamanhoLista = atoi(argv[1]);
    char *arquivoSaida = argv[2];

    // Abrir o arquivo de saída
    FILE *arquivo = fopen(arquivoSaida, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    srand(time(NULL));

    criaListas(arquivo, tamanhoLista);

    fclose(arquivo);
    printf("Lista de %d produtos gerada e salva em %s\n", tamanhoLista, arquivoSaida);

    return 0;
}
