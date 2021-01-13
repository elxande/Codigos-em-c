#include <stdio.h>

double media_frente(double vet[] , int tam, double *m){
    double ma = 0 , md = 0 ;
    for (int i = 0; i < tam; i++) {
        ma += vet[i];
				if(i == tam-1){
					vet[i] = vet[i];
					md += vet[i];
				}else {
        	vet [i] = (vet[i] + vet[i+1])/2.0;
					md += vet[i];
				}
        
    }
    ma = ma/tam;
    *m = md/tam;
    return ma;
}

int main () {
		int n;
		scanf("%d", &n);
        double v[n];
		for(int i=0; i<n; i++){
			scanf("%lf", &v[i]);
		}

    double mediad, mediaa;

    mediaa = media_frente (v, n, &mediad);
    printf("Media antes: %lf\n", mediaa);
    printf("Media depois: %lf\n", mediad);
    return 0 ;
}
