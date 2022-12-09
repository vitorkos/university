#include <stdio.h>
#include <stdlib.h>

struct Record
{
    char title[20];
    char author[20];
    char theme[20];
    int code;
};

int search()
{

}

int main()
{
    int n;
    scanf("%d", &n);

    struct Record *livro;
    livro = (struct Record *) malloc (n * sizeof(Record));

    
}