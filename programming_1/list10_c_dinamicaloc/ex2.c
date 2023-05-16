#include<stdio.h>
#include<stdlib.h>

int main()
{
    int class1, class2, i;
    int *pos1, *pos2;

    printf("enter the size of the first class: ");
    scanf("%d", &class1);
    printf("enter the size of the second class: ");
    scanf("%d", &class2);

    //aloca o tamanho do vetor com base em T1 e T2
    pos1 = (int *) malloc(class1 * sizeof(int));
    pos2 = (int *) malloc(class2 * sizeof(int));
    //atribui valores as posi��es dos vetores
    for(i = 0; i < class1; i++){
        printf("enter the matricula of the student %d of the first class", i);
        scanf("%d", &pos1[i]);
    }
    for(i = 0; i < class2; i++){
        printf("enter the matricula of the student %d of the second class", i);
        scanf("%d", &pos2[i]);
    }
    //imprime os valores dos vetores
    for(i = 0; i < class1; i++){
        printf("the matricula of the student %d of the first class is: %d ", i, pos1[i]);
    }
    for(i = 0; i < class2; i++){
        printf("the matricula of the student %d of the second class is: %d ", i, pos2[i]);
    }

    return 0;
}