#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[51];
    double altura;
}nomeAltura;



int get_modelo(nomeAltura na[], int size, double alt){
    int ini = 0;
    int fim = size-1;
    int meio;
    int rm1, rm2;//variáveis para salvar o valor da altura mais próxima
    double r1 = 0, r2 = 0;//variáveis para comparar a altura mais próxima
    while (ini <= fim){
        meio = (ini+fim)/2;
        if (na[meio].altura == alt){
            printf("%s\n", na[meio].nome);
            break;
        }
        else if(na[meio].altura < alt){
            ini = meio+1;
            r1 = na[meio].altura-alt;
            rm1 = meio;
        }
        else{
            fim = meio-1;
            r2 = alt-na[meio].altura;
            rm2 = meio;
        }
    }
    if(r1 > r2){
        printf("%s\n", na[rm1].nome);
    }
    else{
        printf("%s\n", na[rm2].nome);
    }
}

int main(){
    int qtd;
    double alt;
    nomeAltura  na[1001];

    scanf("%d", &qtd);
    scanf("%lf", &alt);

    for(int i=0; i<qtd; i++){
        scanf("%s %lf", na[i].nome, &na[i].altura);
    }
    get_modelo(na, qtd, alt);
    
    return 0;
}