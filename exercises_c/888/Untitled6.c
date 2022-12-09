#include<stdio.h>

float imc(float kg, float alt)
{
    return kg / (alt * alt);
}
char cond(float imc)
{
    if (imc < 18.5){
        return "abaixo d peso";
    }
    else if (imc >= 18.5 && imc <= 24.9){
        return "peso normal";
    }
    else if (imc >= 25 && imc <= 29.9){
        return "sobrepeso";
    }
    else if(imc >= 30){
        return "obeso";
    }
}



int main()
{
    float kg, alt, i;
    char  c;
    printf("insira o seu pso em quilos e sua altura: ");
    scanf("%f%f", &kg, &alt);

    i = imc(kg, alt);
    c = cond(i);

    printf("o seu imc eh de %f e a sua condicao eh de %c", i, c);

    return 0;
}
