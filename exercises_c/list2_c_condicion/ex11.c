#include <stdio.h>

int main()
{
    int age;
    int stature;
    printf("VIKING BOAT - 1,5m - 12yo\nELEVATOR OF DEATH - 1,4m -14yo\nFINAL KILLER - 1,7m - 16yo\n");
    printf("enter your age: "); scanf("%d", &age);
    printf("enter your stature in cms: "); scanf("%d", &stature);

    if (age >= 16 && stature >=170){
        printf("you can enter in all toys");
    }
    else if (age >= 12 && stature >= 150){
        printf("you can enter in only one toy");
    }
    else if(age >= 14 && stature < 150){
        printf("you can enter in only one toy");
    }
    else if(age >= 14 && stature >= 150){
        printf("you can enter in two toys");
    }
    else if(age < 12){
        printf("you cant enter in any of the toys");
    }

    return 0;
}