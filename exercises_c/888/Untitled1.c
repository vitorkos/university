#include<stdio.h>

int altidade(int alt, int idade){
    if (alt < 140){
        return 0;
    }
    else if(alt >= 170 && idade >= 16){
        return 3;
    }
    else if(alt >= 150 && alt < 170 && idade >= 14 && idade > 16){
        return 2;
    }
    else if(alt >= 170 && idade >= 14 && idade < 16){
        return 2;
    }
    else{
        return 1;
    }
}

int main()
{
    int alt, idade, a;
    printf("insira a altura em cms e a idade: ");
    scanf("%d%d", &alt, &idade);
    a = altidade(alt, idade);

    printf("a pessoa pode andar em %d brinquedos", a);

    return 0;
}
