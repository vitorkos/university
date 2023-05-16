#include <stdio.h>

int main()
{
    int id;
    float workehours;
    float valuephour;

    printf("insert the worker ID, the mount of worked hours and the value per hour: ");
    scanf("%d%f%f", &id, &workehours, &valuephour);

    float salary = valuephour * workehours;

    printf("WORKER ID: %d\nSALARY: $%.2f", id, salary);

    return 0;
}