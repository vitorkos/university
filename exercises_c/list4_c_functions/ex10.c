#include <stdio.h>

void f_season(int day, int mouth)
{
    if (mouth == 12 || mouth == 1 || mouth == 2)
    {
        printf("Winter");
    }
    else if (mouth == 3 || mouth == 4 || mouth == 5)
    {
        printf("Spring");
    }
    else if (mouth == 6 || mouth == 7 || mouth == 8)
    {
        printf("Summer");
    }
    else if (mouth == 9 || mouth == 10 || mouth == 11)
    {
        printf("Autumn");
    }
    else
    {
        printf("Invalid mouth");
    }
}

int main()
{
    int day, mouth;
    printf("Enter a day and a mouth: ");
    scanf("%d %d", &day, &mouth);

    f_season(day, mouth);

    return 0;
}