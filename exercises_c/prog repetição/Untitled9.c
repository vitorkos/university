#include<stdio.h>

int main()
{
    int n;
    int media, numeros;
    int numeros2 =0;
    int count = 1;
    printf("insira a quantidade de numeros para calcular a media: ");
    scanf("%d", &n);

    for(count = 1; count <= n; count++){
        printf("insira um numero para calcular a media");
        scanf("%d", &numeros);
        numeros2 = numeros2 + numeros;
        media = numeros2 / n;
        if(n == count){
            printf("a media entre os numeros é de %d", media);
        }
        else{}
    }
    return 0;
}
