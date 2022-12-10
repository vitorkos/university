#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    char inversa[100];

    printf("insira uma string: ");
    fgets(str, 100, stdin);

    int tamanho = strlen(str[100]) - 1;

    for(int i = 0; str[i] != '\n'; i++){
            for(tamanho; tamanho != '0'; tamanho--){
                inversa[i] = str[tamanho];
            }
    }
    printf("%s", inversa);

    return 0;
}
