#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int v[], int size, int x){
    int ini = 0;
    int fim = size-1;
    int m;
    int result = -1;
    while(ini <= fim){
        m = (ini+fim)/2;
        if (v[m] == x){
            result = m;
            fim = m-1;
        }
        else if(v[m] > x){
            fim = m-1;
        }
        else{
            ini = m+1;
        }
    }
    return result;
}

int main(){
    int nElem, consult, x, r;
    int *vet;

    scanf("%d%d", &nElem, &consult);

    vet = (int *)malloc(nElem*sizeof(int));
    for (int i=0; i<nElem; i++){
        scanf("%d", &vet[i]);
    }

    for (int j=0; j<consult; j++){
        scanf("%d", &x);
        r = buscaBinaria(vet, nElem, x);
        printf("%d\n", r);
    }
    free(vet);
    return 0;
}