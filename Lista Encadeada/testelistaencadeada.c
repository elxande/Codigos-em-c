#include <stdio.h>
#include "listaencadeada.h"

int main() {
    lista* l = createList();
    add(l, 10);
    add(l, 20);
    add(l, 30);
    add(l, 40);
    add(l, 50);

    printList(l);
    printf("Tamanho da lista antes de remover:\n");
    printf("%d \n", size(l));
    removeBack(l);
    printf("\n");
    printf("Tamanho da lista depois de remover:\n");
    size(l);
    insertPosition(l, 11, 1);
    printList(l);

    printf("\n");
    //printf("%d\n",hasElement(*l, 40));


    return 0;
}