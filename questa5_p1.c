#include<stdio.h>

int qtd_letra(char vet[], char c){
    int cont=0, p = 0;
    for(int i=0; vet[i] != '\0'; i++){
        if(vet[i] == c && p == 0){
            cont++;
            p = 1;
        }
        else if(vet[i] == ' ' && vet[i+1] != ' '){
            p = 0;
        }
    }
 return cont;
}

int main() {
    char c; 
    scanf("%c\n", &c);

    char frase[100];
    scanf("%[^\n]s", frase);

    printf("%d\n", qtd_letra(frase, c));

    return 0;
}