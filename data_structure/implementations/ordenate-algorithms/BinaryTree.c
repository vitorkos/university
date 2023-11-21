#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct noArv{
    char info;
    struct noArv* esq;
    struct noArv* dir;
};

typedef struct noArv noArv;

noArv* arvCriaVazia(void){
    return NULL;
}

noArv* arvCria(char c, noArv* sae, noArv* sad){
    noArv* p = (noArv*)malloc(sizeof(noArv));
    if(p == NULL){exit(1);}
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arvVazia(noArv* a){
    return a ==NULL;
}

noArv* arvLibera(noArv* a){
    if(!arvVazia(a)){
        arvLibera(a->esq);
        arvLibera(a->dir);
        free(a);
    }
    return NULL;
}

int arvPertence(noArv* a, char c){
    if(arvVazia(a)){return 0;}
    else{
        return a->info == c ||
                arvPertence(a->esq, c) ||
                arvPertence(a->dir, c);
    }
}

void arvImprime(noArv* a){
    if(!arvVazia(a)){
        printf("%c\n", a->info);
        arvImprime(a->esq);
        arvImprime(a->dir);
    }
}

int main(){
    noArv* a = arvCria('a',
                        arvCria('b', arvCriaVazia(),
                        arvCria('d', arvCriaVazia(), arvCriaVazia())),
               
               arvCria('c', 
                        arvCria('e', arvCriaVazia(), arvCriaVazia()),
                        arvCria('f', arvCriaVazia(), arvCriaVazia())
               ));
    printf("%d", a->esq->dir->info);
}og