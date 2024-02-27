// incluindo bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNÇÕES DE HASHING( TRANSFORMAÇÃO DAS CHAVES )

//transformação de chaves numericas
//// h(k) = K % M; k = chave, M = tamanho do vetor de endereços

//transformação de chaves não numericas 
//cria um peso para cada caractere

    /*vetor dos pesos*//*tamanho da chave*/ 
void geraPesos(int p[],int n){
    //utiliza o tempo como gerador dos valores aleatorios
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        // itera e cria um peso para cada caractere
        p[i] = 1 + (int) (10000.0 * rand() / RAND_MAX);
    }
}

//função de hashing ( retorna o indice daquela chave )
    /*chave*/ /*vetor de pesos*/ /*tamanho do vetor*/ /*tamanho do vetor pesos*/ 
int h(char *chave, int p[], int m, int tam_p){
    unsigned int soma = 0;
    /*comprimento da chave*/
    int comp = strlen(chave);
    for(int i = 0; i < comp; i++){
        /*itera sob o comprimento da chave*/
        /*a cada iteração, incrementa a soma com (caractere i * resto de peso da posicao i / tamanho do vetor p)*/
        soma += (unsigned int) chave [i] * p[i % tam_p];
    }
    //retorna o resto da soma pelo tamanho do vetor de endereços
    return soma % m;
}













// chamada do hashmap (funcao principal)
int main(){
    return 0;
}