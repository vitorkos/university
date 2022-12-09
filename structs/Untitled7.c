#include<stdio.h>
#include<stdlib.h>

struct ficha
{
    char titulo[20];
    char autor[20];
    char assunto[20];
    int codigo;
};

void atb(struct ficha *livro, int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        fgets(livro[i]->titulo, 20, stdin);
        fgets(livro[i]->autor, 20, stdin);
        fgets(livro[i]->assunto, 20, stdin);
        scanf("%d", &livro[i]->codigo);
    }
}

void exb(struct ficha *livro, int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("%s", livro[i]->nome);
        printf("%s", livro[i]->autor);
        printf("%s", livro[i]->assunto);
        printf("%d", livro[i]->codigo);
    }
}

int main()
{
    int n;
    printf("insira quantos livros vão ser cadastrados: ");
    scanf("%d", &n);

    struct ficha *livro;

    livro = (struct ficha *) malloc (n * sizeof(struct ficha));
    atb(livro, n);
    exb(livro, n);
}
