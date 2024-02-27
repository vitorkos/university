// incluindo bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNÇÕES DE HASHING( TRANSFORMAÇÃO DAS CHAVES )

//transformação de chaves numericas
//// h(k) = K % M; k = chave, M = tamanho do vetor de endereços

//transformação de chaves não numericas 
//cria um peso para cada caractere
void geraPesos(/*vetor dos pesos*/int p[],/*tamanho da chave*/ int n){
    //utiliza o tempo como gerador dos valores aleatorios
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        // itera e cria um peso para cada caractere
        p[i] = 1 + (int) (10000.0 * rand() / RAND_MAX);
    }
};














// chamada do hashmap (funcao principal)
int main(){
    return 0;
}