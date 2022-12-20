#include<stdio.h>

struct cadastre
{
    char name[20];
    char gender[20];
    char mode[20];
    char plataform[20];
    int position;
};

void f_enter(struct cadastre games[], int tam)
{
    int i;

    for(i = 0; i < tam; i++){
        printf("enter the name of the game %d: " , i);
        fgets(games[i].name, 20, stdin);
        printf("enter the gender(shooter, rpg, adventure...):");
        fgets(games[i].gender, 20, stdin);
        printf("enter the game mode(singleplayer, multiplayer, coop...): ");
        fgets(games[i].mode, 20, stdin);
        printf("enter the platform(PS4, PC, XBOX...): ");
        fgets(games[i].plataform, 20, stdin);
        printf("enter the classification(1 to 5):");
        scanf("%d", &games[i].position);
    }
}

void f_show(struct cadastre games[], int tam)
{
    int i;

    for(i = 0; i < tam; i++){
        printf("NAME: %s", games[i].name);
        printf("GENDER: ",games[i].gender);
        printf("MODE: %s", games[i].mode);
        printf("PLATAFORM: %s", games[i].plataform);
        printf("CLASSIFICATION:  %d", games[i].position);
    }
}

void f_gender(struct cadastre games[], int tam)
{
    int i;

    char gen[20];
    printf("enter the gender of the game:");
    fgets(gen, 20, stdin);

    printf("GAMES OF THE GENDER %s", gen);

    for(i = 0; i < tam; i++){
        if(gen == games[i].gender){
            printf("NAME: %s", games[i].name);
            printf("GENDER: ",games[i].gender);
            printf("MODE: %s", games[i].mode);
            printf("PLATAFORM: %s", games[i].plataform);
            printf("CLASSIFICATION:  %d", games[i].position);
        }
        else{}
    }
}

void f_class(struct cadastre games[], int tam)
{
    int i;

    int fav;
    printf("enter a classification:");
    scanf("%d", &fav);

    printf("GAMES WITH THE CLASSIFICATION %d", fav);

    for(i = 0; i < tam; i++){
        if(fav == games[i].position){
            printf("NAME: %s", games[i].name);
            printf("GENDER: ",games[i].gender);
            printf("MODE: %s", games[i].mode);
            printf("PLATAFORM: %s", games[i].plataform);
            printf("CLASSIFICATION:  %d", games[i].position);
        }
        else{}
    }
}

int main()
{
    int n;
    printf("enter the number of games:");
    scanf("%d", &n);

    struct cadastre games[n];

    f_enter(games, n);
    f_show(games, n);
    f_gender(games, n);
    f_class(games, n);

    return 0;
}