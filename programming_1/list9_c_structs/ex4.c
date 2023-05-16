#include<stdio.h>

struct card
{
    char name[20];
    int id, level, hp, atk, dfs;
};

void f_insert(struct card character[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("----PERSONAGEM %d----\n\n", i);
        printf("name: \n");
        fgets(character[i].name, 20, stdin);
        printf("id: \n");
        scanf("%d", &character[i].id);
        printf("level: \n");
        scanf("%d", &character[i].level);
        printf("hp: \n");
        scanf("%d", &character[i].hp);
        printf("atk: \n");
        scanf("%d", &character[i].atk);
        printf("dfs: \n");
        scanf("%d", &character[i].dfs);
    }
}

void f_show(struct card character[], int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("----FICHA DO PERSONAGEM %d----\n\n", i);
        printf("NAME: %s \n", character[i].name);
        printf("ID: %d \n", character[i].id);
        printf("LEVEL: %d \n", character[i].level);
        printf("HP: %d \n", character[i].hp);
        printf("ATK: %d \n", character[i].atk);
        printf("DFS: %d \n", character[i].dfs);
    }
}

int main()
{
    int n;
    printf("enter the number of characters to be registered: \n");

    scanf("%d", &n);

    struct card character[n];

    f_insert(character, n);
    f_show(character, n);

    return 0;
}
