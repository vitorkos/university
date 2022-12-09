#include<stdio.h>

struct ficha
{
    char nome[20];
    char genero[20];
    char modo[20];
    char plataforma[20];
    int posicao;
};

void ler(struct ficha jogos[], int tam)
{
    int i;

    for(i = 0; i < tam; i++){
        fgets(jogos[i].nome, 20, stdin);
        printf("insira o genero do jogo(fps, rpg, simulacao, acao...): ");
        fgets(jogos[i].genero, 20, stdin);
        fgets(jogos[i].modo, 20, stdin);
        fgets(jogos[i].plataforma, 20, stdin);
        printf("insira a classificação, de 1 a 5: ");
        scanf("%d", &jogos[i].posicao);
    }
}

void exibir(struct ficha jogo[], int tam)
{
    int i;

    for(i = 0; i < tam; i++){
        printf("nome: %s", jogos[i].nome);
        printf("genero: ",jogos[i].genero);
        printf("modo: %s", jogos[i].modo);
        printf("plataforma: %s", jogos[i].plataforma);
        printf("posicao:  %d", jogos[i].posicao);
    }
}

void genero(struct ficha jogos[], int tam)
{
    int i;

    char gen[20];
    printf("insira o genero: ");
    fgets(gen, 20, stdin);

    printf("JOGOS DO GENERO %s", gen);

    for(i = 0; i < tam; i++){
        if(gen == jogos[i].genero){
            printf("nome: %s", jogos[i].nome);
            printf("genero: ",jogos[i].genero);
            printf("modo: %s", jogos[i].modo);
            printf("plataforma: %s", jogos[i].plataforma);
            printf("posicao:  %d", jogos[i].posicao);
        }
        else{}
    }
}

void classificacao(struct ficha jogos[], int tam)
{
    int i;

    int fav;
    printf("insira um ranking de 1 a 5: ");
    scanf("%d", &fav);

    printf("JOGOS COM RANKING %d", fav);

    for(i = 0; i < tam; i++){
        if(fav == jogos[i].posicao){
            printf("nome: %s", jogos[i].nome);
            printf("genero: ",jogos[i].genero);
            printf("modo: %s", jogos[i].modo);
            printf("plataforma: %s", jogos[i].plataforma);
            printf("posicao:  %d", jogos[i].posicao);
        }
        else{}
}

int main()
{
    int n;

    printf("insira a quantidade de jogos: ");
    scanf("%d", &n);

    struct ficha jogos[n];

    ler(jogos, n);
    exibir(jogos, n);
    genero(jogos, n);
    classificacao(jogos, n);
}
