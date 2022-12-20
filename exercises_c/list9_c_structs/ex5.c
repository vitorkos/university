#include<stdio.h>

struct cadastre
{
    int registration;
    char name[50];
    float note;
};
void f_insertstudents(struct cadastre students[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("enter the registration of the student %d: ", i);
        scanf("%d", &students[i].registration);
        printf("enter the name of the student %d: ", i);
        fgets(students[i].name, tam, stdin);
        printf("enter the note of the student %d: ", i);
        scanf("%f", &students[i].note);
    }
}
void f_showstudents(struct cadastre students[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("STUDENTS:  %d\n\n\n", i);
        printf("\n REGISTRATION: %d", students[i].registration);
        printf("\n NAME: %s", students[i].name);
        printf("\n NOTE: %f", students[i].note);

        if(students[i].note >= 7){
            printf("\n APROVED");
        }
        else if(students[i].note >= 4 && students[i].note < 7){
            printf("\n EXAM");
        }
        else{
            printf("\n REPROVED");
        }

    }
}

void f_showbiggestnote(struct cadastre students[], int tam)
{
    float maior = 0;
    int aux;

    int i;
    for(i = 0; i < tam ; i++){
        maior = students[i].note;
        aux = i;
    }

    printf("the student with the biggest note is %s", students[aux].name);
}


int main()
{
    struct cadastre students[50];

    f_insertstudents(students, 50);
    f_showstudents(students, 50);
    f_showbiggestnote(students, 50);

    return 0;
}
