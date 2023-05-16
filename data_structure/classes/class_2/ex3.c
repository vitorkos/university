#include <stdio.h>

struct Person
{
    char name[40];
    int age;
};
int main()
{
    struct Person p[5];
    for(int i = 0; i < 5; i++){
        printf("Enter the name of person %d: ", i);
        scanf("%s", &p[i].name);
        printf("Enter the age of person %d: ", i);
        scanf("%d", &p[i].age);
    }
    for (int i = 0; i < 5; i++){
        printf("%d - Name : %s - Age : %d", p[i].name, p[i].age);
    }    
    return 0;
}