/*Fa ca um pograma para cadastrar as frutas comercializadas por um mercado. O programa
deve armazenar o nome e o preco de cada item. O usuario informa um inteiro T representando
o total de itens, depois informa cada item. Depois o usuario podera escolher em um menu
quais frutas ele quer comprar (uma ou mais). Quando ele quiser parar de comprar dever ́a
digitar -1, e o programa apresenta o total da compra ao final.

Deve usar ponteiro, struct e alocação
*/

#include<stdio.h>
#include<stdlib.h>

struct Fruit
{
    char name[10];
    float price;
};

void f_name(struct Fruit *fruit, int tam)
{
    for(int i = 0; i < tam; i++){
        printf("insira o nome da fruta %d: ", i);
        setbuf(stdin, 0);
        scanf("%s", (fruit + i)->name);
        
    }
}

void f_price(struct Fruit *fruit, int tam)
{
    for(int i = 0; i < tam; i++){
        printf("insira o preco de %s: ", (fruit + i)-> name);
        scanf("%f", &(fruit + i)-> price); 
    }
}

void f_buylist(struct Fruit *fruit, int tam)
{
    float soma = 0;
    int codigo = 0;

    printf("\n\n\n---LISTA---\n\n");
    for(int i = 0; i < tam; i++){
        printf("%d---%s---R$ %.2f \n",i ,(fruit + i)->name, (fruit + i)->price);
    }
    
    while(codigo != -1){
        printf("insira o codigo da fruta que sera comprada: (insira -1 para parar de comprar)\n");
        scanf("%d", &codigo);

        soma = soma + fruit[codigo].price;
        
        printf("seu carrinho: R$ %.2f \n", soma);
    }

    printf("o total da compra foi de R$%.2f", soma);
}

int main()
{
    int t;
    printf("insira a quantidade de frutas que serao cadastradas: ");
    scanf("%d", &t);

    struct Fruit *fruit;

    fruit = (struct Fruit *) malloc (t * sizeof(struct Fruit));

    f_name(fruit, t);
    f_price(fruit, t);
    f_buylist(fruit, t);

    return 0;
}