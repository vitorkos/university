#include<stdio.h>

int main()
{
    int i;
    int vet[21];

    for(i = 0; i < 21; i++){
        printf("enter the value of the position %d: ", i);
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < 21; i++){
        if(vet[21] == vet[i]){
            printf("the value %d is repeated in the position %d", vet[21], i);
        }
        else{}
    }
    return 0;
}
