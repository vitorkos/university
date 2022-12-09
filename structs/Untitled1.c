//n roda
#include<stdio.h>

struct tp_endereco
{
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[40];
    char estado[3];
    int cep;
};

struct tp_loja
{
    char nome[50];
    int telefone;
    float preco;
    struct tp_endereco endereco;
}
cad_loja[2]
;

void cadastro(struct tp_loja cad_loja)
{
    int i;
    for(i = 0; i != 2; i++){
        printf("---LOJA %d---");

        printf("nome da loja : ");
        gets(cad_loja[i].nome);

        printf("telefone: ");
        scanf("%d", &cad_loja[i].telefone);

        printf("preco: ");
        scanf("%f", &cad_loja[i]);

        printf("rua: ");
        gets(cad_loja[i].endereco.rua);

        printf("numero: ");
        scanf("%d", &cad_loja[i].endereco.numero);

        printf("bairo: ");
        gets(cad_loja[i].endereco.bairro)

        printf("cidade: ");
        gets(cad_loja[i].endereco.cidade);

        printf("estado: ");
        gets(cad_loja[i].endereco.estado);

        printf("cep: ");
        scanf("%d", &cad_loja[i].endereco.cep);
    }
}

void media(struct tp_loja cad_loja, float m)
{
    int i;
    m = 0;
    for(i = 0; i =! 2; i++){
        m = m + cad_loja.preco;
    }

    m = m / 2;
}

int main()
{
    cadastro(cad_loja);
    media(cad_loja);

    int i;

    printf("as lojas acimas da media são: ")
    for(i = 0; i != 2; i++){
        if(cad_loja[i].preco > m){
            printf("%s", cad_loja.nome)
        }
        else{}
    }

    return 0;
}

