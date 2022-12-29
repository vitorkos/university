#include<stdio.h>
#include<stdlib.h>

struct cadastre
{
    char title[20];
    char author[20];
    char subject[20];
    int code;
};

void atb(struct cadastre *book, int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("BOOK: %d\n\n\n", i);
        fgets(book[i].title, 20, stdin);
        printf("author: ");
        fgets(book[i].author, 20, stdin);
        printf("subject: ");
        fgets(book[i].subject, 20, stdin);
        printf("code: ");
        scanf("%d", &book[i].code);
    }
}

void exb(struct cadastre *book, int tam)
{
    int i;
    for(i = 0; i < tam; i++){
        printf("BOOK %d:  %s", i, book[i].title);
        printf("AUTHOR:  %s", book[i].author);
        printf("SUBJECT:  %s", book[i].subject);
        printf("CODE: %d", book[i].code);
    }
}

int main()
{
    int n;
    printf("enter the number of books:");
    scanf("%d", &n);

    struct cadastre *book;

    book = (struct cadastre *) malloc (n * sizeof(struct cadastre));
    atb(book, n);
    exb(book, n);

    return 0;
}