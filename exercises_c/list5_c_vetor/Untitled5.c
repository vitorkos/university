#include<stdio.h>

int main()
{
    int n, i;
    float imposto;
    printf("insira a quantidade de funcionarios: ");
    scanf("%d", &n);
    float vet[n];
    if(n > 50){
        printf("o maximo de funcionarios eh 50");
    }
    else{
        for(i = 0; i < n; i++){
            printf("insira o salario do funcionario %f", vet[i]);
            scanf("%f", &vet[i]);
        }
        for (i = 0; i < n; i++){
            if (vet[i] <= 1904){
                printf("o funcionario %d esta isento de imposto", i);
            }
            else if(vet[i] > 1904 && vet[i] <= 2827){
                imposto =vet[i] * 7.5;
                printf("o funcionario %f tem um imposto de %f", vet[i], imposto);
            }
            else if(vet[i] > 2827 && vet[i] <= 3751){
                imposto =vet[i] * 15;
                printf("o funcionario %f tem um imposto de %f", vet[i], imposto);
            }
            else if(vet[i] > 3751 && vet[i] <= 4665){
                imposto =vet[i] * 22.5;
                printf("o funcionario %f tem um imposto de %f", vet[i], imposto);
            }
            else if(vet[i] > 4665){
                imposto =vet[i] * 27.5;
                printf("o funcionario %f tem um imposto de %f", vet[i], imposto);
            }
        }


    }
    return 0;
}
