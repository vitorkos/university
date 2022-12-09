#include<stdio.h>

float media(float x, float y)
{
    return (x + y) / 2;
}

float mediapon(float x, float y)
{
    return ((x * 3) + (y * 2)) / 5;
}

float mediah(float x, float y)
{
    return 2 / ((1/x) + (1/y));
}


int main()
{
    float x, y;
    char l;
    float m, mp, mh;
    printf("insira dois valores e a letra da funcao");
    scanf("%f%f%c", &x, &y, &l);

    m = media(x, y);
    mp = mediapon(x, y);
    mh = mediah(x, y);

    if (l = 'a'){
        printf("a media entre os dois valores eh: %f", m);
    }
    else if(l = 'p'){
        printf("a media ponderado entre os dois valores eh : %f", mp);
    }
    else if(l = 'h'){
        printf("a media harmonica entre os dois valores eh %f", mh);
    }

    return 0;
}
