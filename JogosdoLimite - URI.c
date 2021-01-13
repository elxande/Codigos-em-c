#include <stdio.h>

int main() {
  int N, T0, L, Si, i; 
  int pontosA=0, pontosB=0;

  scanf("%d %d %d", %N,%T0,%L);
  for(i=1; i<N; i++){
  	scanf("%d", &Si);
  	if (i%2!=0){
  		if ((Si-T0)<=L){
  			pontosA++;
  		}
  	}else{
  		if ((Si-T0)<=L){
  			pontosB++;
  		}
  	}
  }


  return 0;
}

