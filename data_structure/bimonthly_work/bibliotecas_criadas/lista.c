#include "lista.h"

void criaListas(FILE *arquivo, int tamanho) {
    //números aleatorios
    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        // Gerar dados para o produto
        char nome[20];
        sprintf(nome, "FEIJAO");
        int codigo = 10000 + i;
        float valor = i;
        int dia = rand() % 28 + 1;
        int mes = rand() % 12 + 1;
        int ano = 2023 + rand() % 3;

        // Escrever os dados no arquivo
        fprintf(arquivo, "PRODUTO %s %d %.2f %d %d %d\n", nome, codigo, valor, dia, mes, ano);
    }
}