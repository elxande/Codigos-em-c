#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

lista *createList() {
    lista* l = (lista*)malloc(sizeof(lista));
    l-> inicio = NULL;
    return l;
}

void add(lista *l, int v){
    node *novo=(node*)malloc(sizeof(node));
    novo->val=v;
    novo->next=NULL;
    if(l->inicio == NULL) l->inicio=novo;

    else{
        node *p=l->inicio;
        while (p->next != NULL) p = p->next;
        p->next = novo;
    }
}

void printList(lista *l){
    if(isEmpty(*l) == 0){    
        node *p = l-> inicio;
        while(p != NULL){
            printf("%d\n", p->val);
            p = p->next;
        }
    }else printf("Lista Vazia!\n");
}

int isEmpty(lista l){
    if(l.inicio == NULL) return 1;

    else return 0;
}

void removeBack(lista *l){
    if(isEmpty(*l) == 0){
        node *p = l->inicio;
        node *aux = NULL;
        if(p->next == NULL) {
            aux = p;
            l->inicio = NULL;
            free(aux);
        }else {
            while(p->next != NULL){
                aux = p;
                p = p->next;
            }
        }
        aux->next = NULL;
        free(p);
    }else printf("Lista Vazia!\n");
}

int size(lista *l){
    if(isEmpty(*l) == 0){
        node *p = l->inicio;
        int cont = 0;
        while(p != NULL){
            p = p->next;
            cont++;
        }
        return cont;
    }else printf("Lista está Vaazia!\n");
}

int hasElement(lista l, int v){
    if(isEmpty(l) == 0){
        int pos = 0;
        node *p = l.inicio;
        while(p != NULL){
            if(p->val == v) return pos;

            p = p->next;
            pos++;
        }
        return -1;
    }
}

int insertPosition(lista *l, int v, int pos){
    if(isEmpty(*l) == 0){
        int ind = 0;
        node *p = l->inicio;
        node *aux = NULL;
        node *novo=(node*)malloc(sizeof(node));
        novo->val=v;
        while(p != NULL){
            aux = p;
            if(ind == pos){
                
                p->next = novo;
                novo->next = aux;
                return 0;
            }else if(ind == 0){
                aux = p;
                l->inicio = novo;
                novo->next = aux;
            }
            p = p->next;
            ind++;
        }
    }
}

/*int removePosition(lista *l, int pos){
    if (isEmpty(*l) == 0){
        ind
    }
}*/