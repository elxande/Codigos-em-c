#include<stdio.h>
#include<stdlib.h>

#define max 100
typedef struct{
    int topo;
    int vet[max];
}pilha;

pilha* criaPilha(){
    pilha *p=(pilha*)malloc(sizeof(pilha));
    p->topo = 0;
    return p;
}

int push(pilha *p, int v){
    if(p->topo<max){
        p->vet[p->topo]=v;
        p->topo++;
        return 0;
    }
    return -1;
}

int pop(pilha *p){
    int ret = 0;
    if(p->topo > 0){
        ret = p->vet[p->topo-1];
        p->topo--;
    }
    return ret;
}

void printPilha(pilha *p){
    printf("\nPilha=[");
    for(int i=0; i <p->topo; i++){
        if(i == p->topo) printf("*%d", p->vet[i]);

        else printf("%d ", p->vet[i]);
    }
    printf("]");
}