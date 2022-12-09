/*Implemente uma fun ̧c ̃ao que receba como parˆametro dois 
vetores vetX e vetY de tamanho n. A fun ̧c ̃ao deve retornar
 o ponteiro para um vetor soma de tamanho n alocado 
 dinamicamente,em que soma = vetX + vetY.*/

 #include <stdio.h>
 #include <stdlib.h>

 int *soma(int *vetor1, int *vetor2, int tam)
 {
    int *vet;
    vet = (int*) malloc(tam * sizeof(int));
    for(int i = 0; i < tam; i++){
        vet[i] = vetor1[i] + vetor2[i];
    }
    return *vet;
 }

 int main()
 {
    int *vet1, *vet2;
    int n;
    scanf("%d", &n);

    vet1 = (int *) malloc (n * sizeof(int));
    vet2 = (int *) malloc (n * sizeof(int));

    printf("insira o primeiro vetor: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
    }
    printf("insira o segundo vetor: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
    }

    soma(vet1, vet2, n);

    printf("pspsps");

    return 0;
 }