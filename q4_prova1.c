#include <stdio.h>
#include <stdlib.h>

int main (){
    char ent[101];
    scanf("%[^\n]s", ent);

    for(int i=0; ent[i] != '\0'; i++){
        if(ent[i+1] == ' ' && ent[i] != ' '){
            printf("%c", ent[i]);
        }
        if(ent[i+1] == '\0'){
            printf("%c\n", ent[i]);
        }
    }

    return 0;
}