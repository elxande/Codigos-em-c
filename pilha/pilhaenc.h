#include<stdio.h>
#include <stdlib.h>

struct no {
    int val;
    struct no *prox;
};
typedef struct no no;

typedef struct {
    no *inicio;
} pilha;

pilha* criaPilha();

void push(pilha *p, char v);

int pop(pilha *p);

int pilha_vazia (pilha *p);

void pilha_libera (pilha *p);

void printPilha (pilha *p);