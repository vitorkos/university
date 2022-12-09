#include<stdio.h>

struct ficha
{
    char nome[20];
    int idade;
    float altura;
    float peso;
};

void inserealunos(struct ficha aluno[], int tam)
{
    int i;
    for(i = 0;i < tam; i++){
        printf("ALUNO %d\n\n\n", i);
        printf("nome: ");
        fgets(aluno[i].nome, 20, stdin);
        printf("idade: ");
        scanf("%d", &aluno[i].idade);
        printf("altura: ");
        scanf("%f", &aluno[i].altura);
        printf("peso: ");
        scanf("%f", &aluno[i].peso);
    }
}

void exibealunos(struct ficha aluno[], int tam)
{
    int i;
    for(i = 0;i < tam; i++){
        printf("ALUNO %d\n\n\n", i);
        printf("nome: %s", aluno[i].nome);
        printf("idade: %d", aluno[i].idade);
        printf("altura: %f", aluno[i].altura);
        printf("peso: %f", aluno[i].peso);
}

int main()
{


    struct ficha aluno[20];

    inserealunos(aluno, 20);
    exibealunos(aluno, 20);

    return 0;
}
