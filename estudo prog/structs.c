/*

Structs ou Registros definem tipos de dados que agrupam variáveis sob
um mesmo tipo
A sua ideia é armazenar dados de uma mesma entidade usando uma única variavel

Por exemplo
Se preciso armazenar a altura, o peso, a idade de uma pessoa,
pode-se criar uma struct chamada Pessoa e agrupar os dados em um unico
tipo de dado

dessa forma, essa variável seria declarada da seguinte forma:

STRUCT NOMEDAESTRUTURA{
    TIPO1 DADO1;
    TIPO2 DADO2;
    TIPO3 DADO3
    ...
}POSSIVEL VARIAVEL PARA REFERENCIAR;

ASSIM

struct {
    flaot peso;
    int idade;
    float altura;

}pessoa;

apos isso, é possivek criar variaveis do tipo pessoa

pessoa joao, p1, p2;
...

Para acessar os campos de uma struct, usa a sintaxe
NOMEDAVARIAVEL.NOMEDOCAMPO

joao.idade = 15;
joao.peso = 60.5;
joao. altura = 1.75;


*/

#include<stdio.h>

struct dados
{
    char nome[200];
    int numero;
    float nota;
};

int main()
{
    struct dados aluno1;

    printf("insira os dados do aluno\n\n\n");

    printf("insira o nome do aluno: ");
    gets(aluno1.nome);

    printf("\ninsira o numero do aluno: ");
    scanf("%d", &aluno1.numero);

    printf("\ninsira a nota do aluno: ");
    scanf("%f", &aluno1.nota);


    printf("\n\nMOSTRAR OS DADOS DO ALUNO\n\n");

    printf("nome: %s \n", aluno1.nome);

    printf("numero: %d \n", aluno1.numero);

    printf("nota: %f \n", aluno1.nota);

    return 0;
}
