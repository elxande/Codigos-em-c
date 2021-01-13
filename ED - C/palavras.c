#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char str[51];
    int peso;
}palavraPeso;

palavraPeso pp[100];

int compare(const void *a, const void *b) {
    palavraPeso *p1 = (palavraPeso*)a;
    palavraPeso *p2 = (palavraPeso*)b;

    int sp1 = strlen(p1->str);
    int sp2 = strlen(p2->str);

    if(sp1 == sp2) {
        return (p2->peso - p1->peso);
    }
    else {
        return sp1 - sp2;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i < n; i++){
        scanf("%s %d", pp[i].str, &pp[i].peso);
    }
    qsort(pp, n, sizeof(palavraPeso), compare);
    for(int j=0; j < n; j++){
        printf("%s\n", pp[j].str);
    }
    
    return 0;
}