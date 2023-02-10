#include<stdio.h>

struct cadaster
{
    char name[20];
    int age;
    float height;
    float weight;
};

void f_enterstudents(struct cadaster student[], int tam)
{
    int i;
    for(i = 0;i < tam; i++){
        printf("STUDENT:  %d\n\n\n", i);
        printf("name: ");
        fgets(student[i].name, 20, stdin);
        printf("age: ");
        scanf("%d", &student[i].age);
        printf("height: ");
        scanf("%f", &student[i].height);
        printf("weight: ");
        scanf("%f", &student[i].weight);
    }
}

void f_showstudents(struct cadaster student[], int tam)
{
    int i;
    for(i = 0;i < tam; i++){
        printf("ALUNO %d\n\n\n", i);
        printf("NAME: %s", student[i].name);
        printf("AGE: %d", student[i].age);
        printf("HEIGHT: %f", student[i].height);
        printf("WEIGHT: %f", student[i].weight);
    }
}

void f_younger_heavier(struct cadaster student[], int tam)
{
    int i, younger = 0;
    float heavier = 0;
    char name_younger[20], name_heavier[20];
    for(i = 0;i < tam; i++){
        if(student[i].age < younger){
            younger = student[i].age;
            strcpy(name_younger, student[i].name);
        }
        if(student[i].weight > heavier){
            heavier = student[i].weight;
            strcpy(name_heavier, student[i].name);
        }
    }
    printf("THE YOUNGER IS: %s", name_younger);
    printf("THE HEAVIER IS: %s", name_heavier);
}

int main()
{
    struct cadaster student[20];

    f_enterstudents(student, 20);
    f_showstudents(student, 20);
    f_younger_heavier(student, 20);

    return 0;
}