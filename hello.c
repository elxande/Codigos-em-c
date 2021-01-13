#include <stdio.h>

int main() {
  int N, T0, L, Si, i; 
  int pontosA=0, pontosB=0;

  scanf("%d %d %d", &N,&T0,&L);

	if (1<=N<60 && N%2!=0 && 1<=T0<=N && 1<=L<=10){
		for(i=1; i<N; i++){
			scanf("%d", &Si);
			if (i%2!=0){
				if ((Si-T0)>0){
					if ((Si-T0)<=L){
						pontosA += Si-T0;
						T0 = Si;
					}
				}
				else{
					if ((Si-T0)<=L){
						pontosA += T0-Si;
						T0 = Si;
					}
				}
			}
			else{
				if ((Si-T0)>0){
					if ((Si-T0)<=L){
						pontosB += Si-T0;
						T0 = Si;
					}
				}
				else{
					if ((Si-T0)<=L){
						pontosB += T0-Si;
						T0 = Si;
					}
				}
			}
			
		}
	}
  printf("%d %d\n", pontosA, pontosB);


  return 0;
}