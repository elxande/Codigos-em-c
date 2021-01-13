#include <stdio.h>
#include <stdlib.h>
#include "pilhaenc.h"

int main(){
    pilha *p = criaPilha();
    char ent[101];
    scanf("%s", ent);
    int ok = 1;
    //printf("%s", ent);
    for(int i=0; ent[i] != '\0'; i++){
        if(ent[i]=='(' || ent[i]=='[' || ent[i]=='{'){
            push(p, ent[i]); 
        }
        else if(ent[i]==')' || ent[i]==']' || ent[i]=='}'){
            if(pilha_vazia(p) == 1){
                ok = 0;
                break;
            }else {
               int i = pop(p);
               //if ()
            }
        }else ok = 0;
    }
    if(ok == 1 && pilha_vazia(p) == 1){
        printf("OK\n");
    }else printf("NÃO\n");


    return 0;
}