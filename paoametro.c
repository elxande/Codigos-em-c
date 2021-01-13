#include <stdio.h>

int get_qtdSanduiches(int sands[], int qs, int size){
    int cont = 0;
    for (int i = 0; i < qs; i++){
        cont += sands[i]/size;
    }
    return cont;
}

int main() {
    int qtd_pessoas;
    int qtd_sand;
    int maior_sand = 0;
    int sanduiches[10001];
    scanf("%d", &qtd_pessoas);
    scanf("%d", &qtd_sand);
    for (int i=0; i < qtd_sand; i++){
        scanf("%d", &sanduiches[i]);
        if(sanduiches[i] > maior_sand){
            maior_sand = sanduiches[i];
        }
    }

    int ini =1, fim = maior_sand, m , r = 1;

    while(ini <= fim) {
        m = (ini + fim)/2;
        int va = get_qtdSanduiches(sanduiches, qtd_sand, m);
        if (va >= qtd_pessoas){
            r = m;
            ini = m + 1;
        }
        else{
            fim = m - 1;
        }
    }
    printf("%d\n", r);

    /*for(int i=1; i <= maior_sand; i++){
        int va = get_qtdSanduiches(sanduiches, qtd_sand, i);
        if (va < qtd_pessoas){
            printf("%d\n", i-1);
            break;
        }
    }*/

    return 0;
}