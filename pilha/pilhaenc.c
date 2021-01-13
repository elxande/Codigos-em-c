#include<stdio.h>
#include<stdlib.h>
#include "pilhaenc.h"

pilha *criaPilha(){
    pilha* p = (pilha*) malloc(sizeof(pilha));
    p->inicio = NULL;
    return p;
}

void push(pilha *p, char v){
    no *novo_no = (no*) malloc(sizeof(no));
    novo_no->val = v;
    novo_no->prox = p->inicio;
    p->inicio = novo_no;
}

int pop(pilha *p){
    if (p->inicio != NULL){
        no *aux = p->inicio;
        int v = aux->val;
        p->inicio = aux->prox;
        free(aux);
        return v;
    }
}

int pilha_vazia (pilha *p){
    if(p->inicio == NULL){
        return 1;
    }
    
    return 0;
}

void pilha_libera (pilha *p){
    no *q = p->inicio;
    while(q != NULL){
        no *aux = q->prox;
        free (q);
        q = aux;
    }
    free(p);
}

void printPilha (pilha *p){
    for (no *q=p->inicio; q != NULL; q=q->prox){
        printf("%d\n", q->val);
    }
}