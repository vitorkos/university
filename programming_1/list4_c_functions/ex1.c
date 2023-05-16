#include <stdio.h>

int f_rides(int height, int age)
{
    if (height < 140)
    {
        return 0;
    }
    else if (height >= 170 && age >= 16)
    {
        return 3;
    }
    else if (height >= 150 && height < 170 && age >= 14 && age < 16)
    {
        return 2;
    }
    else if (height >= 170 && age >= 14 && age < 16)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int height, age, rides;
    printf("Enter height in cm and age: ");
    scanf("%d%d", &height, &age);

    rides = f_rides(height, age);

    printf("The person can ride in %d rides", rides);

    return 0;
}