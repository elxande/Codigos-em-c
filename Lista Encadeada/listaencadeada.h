#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
typedef struct node node;

typedef struct {
    node *inicio;
} lista;

lista* createList();

void add(lista *l, int v);

void printList(lista *l);

int isEmpty(lista l);

void removeBack(lista *l);

int size(lista *l);

int hasElement (lista l, int v);

int insertPosition (lista *l, int v, int pos);

int removePosition (lista *l, int pos);

int removeElement (lista *l, int v);

int get (lista l, int pos, int *vret);