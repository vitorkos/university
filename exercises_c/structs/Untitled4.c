#include<stdio.h>

struct ficha
{
    char nome[20];
    int id, level, vida, ataque, defesa;
};

void insere(struct ficha a[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("----PERSONAGEM %d----\n\n", i);
        printf("insira o nome: \n");
        fgets(a[i].nome, 20, stdin);
        printf("insira o id do personagem: \n");
        scanf("%d", &a[i].id);
        printf("insira o level: \n");
        scanf("%d", &a[i].level);
        printf("insira a vida: \n");
        scanf("%d", &a[i].vida);
        printf("insira o ataque: \n");
        scanf("%d", &a[i].ataque);
        printf("insira a defesa: \n");
        scanf("%d", &a[i].defesa);
    }
}

void exibe(struct ficha a[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("----FICHA DO PERSONAGEM %d----\n\n", i);
        printf("NOME: %s \n", a[i].nome);
        printf("ID: %d \n", a[i].id);
        printf("LEVEL: %d \n", a[i].level);
        printf("VIDA: %d \n", a[i].vida);
        printf("ATAQUE: %d \n", a[i].ataque);
        printf("DEFESA: %d \n", a[i].defesa);
    }
}




int main()
{
    int n;
    printf("insira a quantidade de personagens que são ser definidos");

    scanf("%d", &n);

    struct ficha a[n];

    insere(a, n);
    exibe(a, n);

    return 0;
}
