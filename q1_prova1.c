#include <stdio.h>

int main() {
    char nome[20] = "IFPB-CG";
    int dias[5] = {5,3,1,6,7};

    char *p = nome+5;
    nome[4] = '\0';

    for(int i=0; nome[i] != '\0'; i++){
        printf("%c", nome[i]);
    }
    printf("\n");
    for(int i=0; p[i] != '\0'; i++){
        printf("%c", p[i]);
    }
    printf("\n");

    int *q;
    for(int i=0; i<5; i++){
        if(dias[i] == 1){
            q = &dias[i];
        }
    }
    printf("%d\n", q[2]);
    return 0;
}