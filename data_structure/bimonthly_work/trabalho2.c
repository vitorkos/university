#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estoque.h"

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

    for (int i = 0; i < tamanhoLista; i++) {
        // Gerar dados para o produto
        char nome[20];
        sprintf(nome, "FEIJAO");
        int codigo = 100 + i;
        float valor = tamanhoLista - i;
        int dia = rand() % 28 + 1;
        int mes = rand() % 12 + 1;
        int ano = 2023 + rand() % 3;

        // Escrever os dados no arquivo
        fprintf(arquivo, "PRODUTO %s %d %.2f %d %d %d\n", nome, codigo, valor, dia, mes, ano);
    }

    fclose(arquivo);
    printf("Lista de %d produtos gerada e salva em %s\n", tamanhoLista, arquivoSaida);

    return 0;
}
