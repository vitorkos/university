#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct item {
    int valor;
};

typedef struct item Item;

void troca(Item* vet, int i, int j) {
    Item aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

int particiona(Item* vet, int inicio, int fim) {
    int pivo, pivo_indice, i;
    pivo = vet[fim].valor; // Acessar o campo 'valor' da struct
    pivo_indice = inicio;
    for (i = inicio; i < fim; i++) {
        // Verifica se o elemento é <= ao pivo
        if (vet[i].valor <= pivo) { // Acessar o campo 'valor' da struct
            troca(vet, i, pivo_indice);
            pivo_indice++;
        }
    }
    troca(vet, pivo_indice, fim);
    return pivo_indice;
}

void quickSort(Item* vet, int inicio, int fim) {
    if (inicio < fim) {
        // Função particiona retorna o índice do pivo
        int pivo_indice = particiona(vet, inicio, fim);

        // Chamadas recursivas quick sort
        quickSort(vet, inicio, pivo_indice - 1);
        quickSort(vet, pivo_indice + 1, fim);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Item* itens = (Item*)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        scanf("%d", &itens[i].valor);
    }
    quickSort(itens, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", itens[i].valor);
    }
    free(itens);
    return 0;
}