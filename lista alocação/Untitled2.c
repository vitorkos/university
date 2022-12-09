#include<stdio.h>
#include<stdlib.h>



int main()
{
    int t1, t2, i;
    int *p1, *p2;

    printf("insira o tamanho da primeira turma: ");
    scanf("%d", &t1);
    printf("insira o tamanho da segunda turma: ");
    scanf("%d", &t2);

    //aloca o tamanho do vetor com base em T1 e T2
    p1 = (int *) malloc(t1 * sizeof(int));
    p2 = (int *) malloc(t2 * sizeof(int));
    //atribui valores as posições dos vetores
    for(i = 0; i < t1; i++){
        printf("insira a matricula do aluno %d da primeira turma", i);
        scanf("%d", &p1[i]);
    }
    for(i = 0; i < t2; i++){
        printf("insira a matricula do aluno %d da segunda turma", i);
        scanf("%d", &p2[i]);
    }

    return 0;
}
