#include<stdio.h>
int main()
{

    //informando o inteiro T de itens
    int ndefrutas;
    printf("\nInsira o numero de frutas a serem vendidas: ");
    scanf("%d", &ndefrutas);

    //inserindo as frutas, os seus valores e o seu código

    //contador
    int i;

    //matriz das frutas
    char frutas[ndefrutas][15];

    //vetor dos preços
    float precos[ndefrutas];


    //laço de repetição para o nome das frutas
    for (i = 0; i != ndefrutas; i++){
        printf("\nInsira a fruta %d: ", i+1);
        scanf("%s", frutas[i]);
    }

    //laço de repetição para o preço das frutas
    for (i = 0; i != ndefrutas; i++){
        printf("\nInsira o preco da fruta %s: ", frutas[i]);
        scanf("%f", &precos[i]);
    }


    //lista
    printf("\n\n-----Lista-----\n\n");

    for(i = 0; i != ndefrutas; i++){
        printf("\nCOD: %d - %s ----- R$%.2f \n", i, frutas[i], precos[i]);
    }

    //o usuario comprando
    int codigo;
    float total = 0;

    while(codigo != -1){
        printf("\nInsira o codigo das frutas que irá comprar (para SAIR insira -1): ");
        scanf("%d", &codigo);

        for(i = 0; i != ndefrutas; i++){
            if (codigo == i){
                total = total + precos[i];
            }
            else{}
        }
      printf("\nCarrinho: R$%.2f ", total);
    }

    printf("\nTotal a ser pago: R$%.2f ", total);


    return 0;
}
