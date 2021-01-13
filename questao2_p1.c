#include <stdio.h>

int main() {
    int vet1[10], *vet2;
    int i;
    int cont;
    for(i=0; i<10; i++) {
        scanf("%d", &vet1[i]);
    }
    vet2 = vet1;
    for(i=0; i<10; i++) {
        if(vet2[i] < 0) {
            vet2[i] *= -1;
            cont++;
        }
    }
    for(i=0; i<10; i++) {
        printf("%d %d\n", vet1[i], vet2[i]);
    }
    printf("Contador: %d\n", cont);

    return 0;
}