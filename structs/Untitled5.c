#include<stdio.h>

struct cadastro
{
    int matricula;
    char nome[50];
    float nota;
};
//funções
void ledadosalunos(struct cadastro a[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("insira a matricula do aluno %d: ", i);
        scanf("%d", &a[i].matricula);
        printf("insira o nome do aluno %d: ", i);
        fgets(a[i].nome, tam, stdin);
        printf("insira a nota do aluno %d: ", i);
        scanf("%f", &a[i].nota);
    }
}

void exibedadosalunos(struct cadastro a[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("DADOS DO ALUNO %d\n\n\n", i);
        printf("\n MATRICULA: %d", a[i].matricula);
        printf("\n NOME: %s", a[i].nome);
        printf("\n NOTA: %f", a[i].nota);

        if(a[i].nota >= 7){
            printf("\n APROVADO");
        }
        else if(a[i].nota >= 4 && a[i].nota < 7){
            printf("\n EXAME");
        }
        else{
            printf("\n REPROVADO");
        }

    }
}

void exibemaiornota(struct cadastro a[], int tam)
{
    float maior = 0;
    int aux;

    int i;
    for(i = 0; i < tam ; i++){
        maior = a[i].nota;
        aux = i;
    }

    printf("O aluno com a maior nota foi %s", a[aux].nome);
}


int main()
{
    struct cadastro a[50];

    ledadosalunos(a, 50);
    exibedadosalunos(a, 50);
    exibemaiornota(a, 50);

    return 0;
}
