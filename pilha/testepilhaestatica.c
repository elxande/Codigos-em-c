#include <stdio.h>
#include "pilhaestatica.h"
#include<string.h>

int main() {
    int n;
    int v;
    char func[50];

    pilha* p = criaPilha();

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        if(i%2 == 0){
            push(p, i);
        }else if(i%5 == 0){
            printf("Saída: %d\n", pop(p));
        }
    }
    /*push(p, 10);
    push(p, 20);
    push(p, 30);
    push(p, 40);
    push(p, 50);

    printPilha(p);*/

    return 0;
}