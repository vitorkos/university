#include <stdio.h>

struct Passenger
{
    int num;
    char name[30];
    int age;
    char origin[100];
    char destination[100];
    char date[10];
    char time[5];
};

int main()
{
    struct Passenger passengers[44];
    int age_avg = 0;

    for (int i = 1; i <= 44; i++) {
    

        printf("enter the number of the passenger %d: ", i);
        scanf("%d", &passengers[i].num);

        if (passengers[i].num == -1) {
            break;
        }

        printf("enter the name of the passenger %d: ", i);
        fgets(passengers[i].name, 30, stdin);

        printf("enter the age of the passenger %d: ", i);
        scanf("%d", &passengers[i].age);

        printf("enter the origin of the passenger %d: ", i);
        fgets(passengers[i].origin, 100, stdin);

        printf("enter the destination of the passenger %d: ", i);
        fgets(passengers[i].destination, 100, stdin);

        printf("enter the date of the passenger %d: ", i);
        fgets(passengers[i].date, 10, stdin);

        printf("enter the time of the passenger %d: ", i);
        fgets(passengers[i].time, 5, stdin);

        age_avg += passengers[i].age;
    }

    age_avg /= 44;

    for (int i = 2; i <= 44; i++) {
    if ((i / 2) == 0) {
        if (passengers[i].age > age_avg) {
        printf("Passageiro %d (%s) está acima da média da idade com %s anos\n", i, passengers[i].name, passengers[i].age);
            }
        }
    }
}