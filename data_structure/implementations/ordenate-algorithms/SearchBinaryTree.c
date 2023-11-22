#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct noArv{
    int info;
    struct noArv* esq;
    struct noArv* dir;
};
    
typedef struct noArv noArv;

noArv* arvCriaVazia(void){
    return NULL;
}

void arvImprime(noArv* a){
    if(a != NULL){
        arvImprime(a->esq);
        printf("%d\n", a->info);
        arvImprime(a->dir);
    }
}

noArv* arvBusca(noArv* r, int v){
    if(r == NULL){
        return NULL;}
    else if(r->info > v){
        return arvBusca(r->esq, v);
    }
    else if(r->info < v){
        return arvBusca(r->dir, v);
    }
    else{
        return r;
    }
}

noArv* arvInsere(noArv* a, int v){
    if( a== NULL){
        a = (noArv*)malloc(sizeof(noArv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if(v < a->info){
        a->esq = arvInsere(a->esq, v);
    }
    else{
        a->dir = arvInsere(a->dir, v);
    }
    return a;
}

noArv* arvRetira(noArv* r, int v){
    if(r == NULL){return NULL;}
    else if(r->info > v){
        r->esq = arvRetira(r->esq, v);
    }
    else if(r->info < v){
        r->esq = arvRetira(r->dir, v);
    }
    else{ // achou o no para remover
    //nó sem filhos
        if(r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }
        else if(r->esq == NULL){
            noArv* t = r;
            r = r->dir;
            free(t);
        }
        else if(r->dir == NULL){
            noArv* t = r;
            r = r->esq;
            free(t);
        }
        else{
            noArv* f = r->esq;
            while(f->dir != NULL){
                f = f->dir;
            }
            r->info = f->info; //troca as informações
            f->info = v;
            r->esq = arvRetira(r->esq,v);
        }
    }
    return r;
}