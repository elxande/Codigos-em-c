#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct{
    int topo;
    int vet[max];
} pilha;

pilha* criaPilha();

int push(pilha *p, int v);

int pop(pilha *p);

//void printPilha(pilha *p);