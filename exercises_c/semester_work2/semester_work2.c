//pharmacy management system using file handling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct
struct medicine
{
    char name[20];
    float price;
    int quantity;
    char generic[20];
    char type[20];
    char company[20];
};
//funcions

//add medicine
void add_medicine(struct medicine *m)
{
    printf("\nInsira o nome do remédio: ");
    scanf("%s",m->name);
    printf("Insira o preço do remédio: ");
    scanf("%f",&m->price);
    printf("Insira a quantidade em estoque do remédio: ");
    scanf("%d",&m->quantity);
    printf("Insira se o remédio é genérico(sim ou não) : ");
    scanf("%s",m->generic);
    printf("Insira o tipo do remédio: ");
    scanf("%s",m->type);
    printf("Insira a empresa do remédio: ");
    scanf("%s",m->company);
}
//display medicine
void display_medicine(struct medicine *m)
{
    printf("\nName: %s ",m->name); 
    printf("\nPreço do remédio: %f",m->price);
    printf("\nQuantidade em estoque: %d",m->quantity);
    printf("\nGenérico: %s",m->generic);
    printf("\nTipo do remédio: %s",m->type);
    printf("\nEmpresa do remédio: %s\n",m->company);

}
//search medicine and display
void search_medicine(struct medicine *m)
{
    char name[20];
    printf("\nInsira o nome do remédio a ser procurado e exibido: ");
    scanf("%s",name);
    if(strcmp(m->name,name)==0)
    {
        display_medicine(m);
    }
}
//update medicine
void update_medicine(struct medicine *m)
{
    char name[20];
    printf("\nInsira o nome do remédio a ser atualizado: ");
    scanf("%s",name);
    if(strcmp(m->name,name)==0)
    {
        printf("Insira o novo preço do remédio: ");
        scanf("%f",&m->price);
        printf("Insira a nova quantidade em estoque do remédio: ");
        scanf("%d",&m->quantity);
        printf("Insira se o remédio é genérico(sim ou não) : ");
        scanf("%s",m->generic);
        printf("Insira o novo tipo do remédio: ");
        scanf("%s",m->type);
        printf("Insira a nova fábrica do remédio: ");
        scanf("%s",m->company);
    }
}
//delete medicine
void delete_medicine(struct medicine *m)
{
    char name[20];
    printf("\nInsira o nome do remédio a ser deletado: ");
    scanf("%s",name);
    if(strcmp(m->name,name)==0)
    {
        strcpy(m->name,"");
        m->price=0;
        m->quantity=0;
        strcpy(m->type,"");
        strcpy(m->generic,"");
        strcpy(m->company,"");
    }
}

int main()
{
    printf("-----------------------------------------------");
    printf("\nBem vindo ao sistema de gerenciamento de farmácia \n" );
    printf("-----------------------------------------------\n");

    struct medicine m;
    FILE *fp;
    int choice;
    fp=fopen("medicine.txt","w+");
    if(fp==NULL)
    {
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }
    while(1)
    {
        printf("\n 1. Adicionar remédio "); 
        printf("\n 2. Mostar todos os remédios ");
        printf("\n 3. Procurar remédio ");
        printf("\n 4. Atualizar remédio");
        printf("\n 5. Deletar remédio");
        printf("\n 6. Sair");
        printf("\n Insira a opção: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: add_medicine(&m);
                    fwrite(&m,sizeof(m),1,fp);
                    break;
            case 2: rewind(fp);
                    while(fread(&m,sizeof(m),1,fp))
                    {
                        display_medicine(&m);
                    }
                    break;
            case 3: rewind(fp);
                    while(fread(&m,sizeof(m),1,fp))
                    {
                        search_medicine(&m);
                    }
                    break;
            case 4: rewind(fp);
                    while(fread(&m,sizeof(m),1,fp))
                    {
                        update_medicine(&m);
                    }
                    break;
            case 5: rewind(fp);
                    while(fread(&m,sizeof(m),1,fp))
                    {
                        delete_medicine(&m);
                    }
                    break;
            case 6: exit(0);
            default: printf("Escolha invalida");
        }
    }
    fclose(fp);
    return 0;
}