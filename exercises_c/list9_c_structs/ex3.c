//n roda
#include<stdio.h>

struct cadastre
{
    int age;
    char name[20];
    char sex[1];
    char maritalstatus[1];
    int friends;
    int photos;
};

int main()
{
    int n;
    printf("enter the number of clients to be registered:");
    scanf("%d", &n);

    struct cadastre user[n];

    int i;

    for(i = 0; i =! n; i++){
        printf("user %d\n\n\n", i);
        printf("name: ");
        gets(user[i].name);
        fflush(stdin);

        printf("age: ");
        scanf("%d", &user[i].age);
        fflush(stdin);

        printf("\nsex(m ou n): ");
        gets(user[i].sex);
        fflush(stdin);

        printf("\n marital status(s, m, w): ");
        gets(user[i].maritalstatus);
        fflush(stdin);

        printf("friends: ");
        scanf("%d", &user[i].friends);

        printf("photos: ");
        scanf("%d", &user[i].photos);
    }



    for(i = 0; i =! n; i++){
        printf("user %d\n\n\n", i);
        printf("name: %s", user[i].name);
        printf("age %d: ", user[i].age);
        printf("\nsex(m ou n): %s",user[i].sex);

        printf("\n marital status: %s", user[i].maritalstatus);

        printf("friends: %d", user[i].friends);

        printf("photos: %d", user[i].photos);

    }
    return 0;
}