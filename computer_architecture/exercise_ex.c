#include <stdio.h>
int main() {
    int num1, num2, resultado;
    // Solicita o valor das duas variáveis ao usuário
    printf("Digite o valor do primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o valor do segundo número: ");
    scanf("%d", &num2);
    // Realiza a soma e armazena o resultado na terceira variável
    resultado = num1 + num2;
    // Exibe o resultado da soma
    printf("A soma de %d e %d é: %d\n", num1, num2, resultado);
    return 0;
}