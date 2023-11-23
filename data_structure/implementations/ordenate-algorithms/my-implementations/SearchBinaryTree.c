#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct tree{
    int info;
    struct tree* leftKnot;
    struct tree* rightKnot;
};

typedef struct tree Tree;

void createEmpty(){
    return NULL;
}

Tree* createKnot(Tree* t, int v){
    if(t == NULL){
        Tree* new = (Tree*) malloc(sizeof(Tree));
        new->info = v;
        new->leftKnot = new->rightKnot = NULL;
    }
    else if(v < t->info){
        t->leftKnot = createKnot(t->leftKnot, v);
    }
    else{
        t->rightKnot = createKnot(t->rightKnot, v);
    }
    return t;
}

Tree* searchKnot(Tree* t, int v){
    if(t == NULL){
        return NULL;
    }
    else if(t->info < v){
        return searchKnot(t->leftKnot, v);
    }
    else if(t->info > v){
        return searchKnot(t->rightKnot, v);
    }
    else{
        return t;
    }
}

Tree* removeKnot(Tree* t, int v){
    if(t == NULL){
        return NULL;
    }
    else if(t->info < v){
        return removeKnot(t->leftKnot, v);
    }
    else if(t->info > v){
        return removeKnot(t->rightKnot, v);
    }
    else{
        if(t->leftKnot == NULL && t->rightKnot == NULL){
            free(t);
            t = NULL;
        }
        else if(t->leftKnot == NULL){
            Tree* a = t;
            t = t->rightKnot;
            free(a);
        }
        else if(t->rightKnot == NULL){
            Tree* a = t;
            a = a->leftKnot;
            free(a);
        }
        else{
            Tree* f = t->leftKnot;
            while(f->rightKnot != NULL){
                f = f->rightKnot;
            }
            t->info = f->info; //troca as informações
            f->info = v;
            t->leftKnot = arvRetira(t->leftKnot,v);
        }
    }
}

void printTree(Tree* t){
    if(t != NULL){
        printTree(t->leftKnot);
        printf("%d", t->info);
        printTree(t->rightKnot);
    }
}