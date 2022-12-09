//n roda
#include<stdio.h>

int n;
    printf("numero de usuarios a serem cadastrados: ");
    scanf("%d", &n);

struct cadastro
{
    int idade;
    char nome[20];
    char sexo[1];
    char civil[1];
    int qnt_amigos;
    int qnt_fts;
};

int main()
{
    int n;
    printf("numero de usuarios a serem cadastrados: ");
    scanf("%d", &n);

    struct cadastro usuario[n];

    int i;

    for(i = 0; i =! n; i++){
        printf("USUARIO %d\n\n\n", i);
        printf("nome: ");
        gets(usuario[i].nome);
        fflush(stdin);

        printf("idade: ");
        scanf("%d", &usuario[i].idade);
        fflush(stdin);

        printf("\nsex(m ou n): ");
        gets(usuario[i].sexo);
        fflush(stdin);

        printf("\n estado civil(s, n, c, v): ");
        gets(usuario[i].civil);
        fflush(stdin);

        printf("quantidade de amigos: ");
        scanf("%d", &usuario[i].qnt_amigos);

        printf("quantidade de fotos: ");
        scanf("%d", &usuario[i].qnt_fts);
    }



    for(i = 0; i =! n; i++){
        printf("USUARIO %d\n\n\n", i);
        printf("nome: %s", usuario[i].nome);
        printf("idade %d: ", usuario[i].idade);
        printf("\nsex(m ou n): %s",usuario[i].sexo);

        printf("\n estado civil(s, n, c, v): %s", usuario[i].civil);

        printf("quantidade de amigos: %d", usuario[i].qnt_amigos);

        printf("quantidade de fotos: %d", usuario[i].qnt_fts);

    }
    return 0;
}
