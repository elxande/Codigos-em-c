#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int local;
    float grau;
} temperatura;

temperatura temp[1000];

int buscabinaria(temperatura temp[], int size, int x){
    int ini = 0;
    int fim = size-1;
    //int meio;
    
    for(int i=ini ; i<=fim; i++){
        //meio = (ini+fim)/2;
        if (temp[i].local == x){
            return temp[i].grau;
        }
       /* else if (temp[meio].local < x){
            ini = meio+1;
        }
        else {
            fim = meio-1;
        }*/
    }
    return -1;
}

/*void insertionSort(temperatura temp[], int n){
    int i, j;
    temperatura aux;
    
    for (i=0; i<n-1; i++){
        aux = temp[i];
        for (j=1; (j>0) && (aux.local<temp[j-1].local); j--){
            temp[j] = temp[j-1];
        }
        temp[j] = aux;
    }
}*/

int main(){
    int qtdAmostras;
    int qtdConsultas;
    int n_local;
    int res;

    scanf("%d", &qtdAmostras);
    for (int i=0; i<qtdAmostras; i++){
        scanf("%d %f", &temp[i].local, &temp[i].grau);
    }

    //insertionSort(temp, qtdAmostras);

    scanf("%d", &qtdConsultas);
    for (int i=0; i<qtdConsultas; i++){
        scanf("%d", &n_local);
        res = buscabinaria(temp, qtdAmostras, n_local);
        printf("Temperatura no local%d: %d\n", n_local, res);
    }

    return 0;
}