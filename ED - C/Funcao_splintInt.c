#include <stdio.h>
#include <stdlib.h>

int verifyListInt(const char *s){
	int cont = 0;
	int cont1 = 0;
	int i = 0;
	for(i=0;s[i] != '\0'; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cont = 1;
		}else if(s[i] == ' '){
			cont = 1;
		}else{
			cont = 0;
			break;
		}
	}
	if(cont == 1){
		for(i=0;s[i] != '\0'; i++){
			if(s[i] >= '0' && s[i] <= '9' && s[i+1]== ' ' || s[i+1] == '\0' && s[i] != ' '){
				cont1++;
			}
		}
	}
	if(cont1 > 0){
		return cont1;
	}
	return 0;
}

int* splitInt(const char *s, int *size){
	int *v;	
	int quant = verifyListInt(s);
	if (quant == 0){
		size = 0;
		return NULL;
	}else{
		size = quant;
		v = (int*)malloc(quant*sizeof(int));
		for(int i=0; s[i] != '\0'; i++){
			if(s[i] != ' ' && s[i+1] == ' '){
				v[i] = s[i];
			}
		}
	}
	return v;
}

int main(void) {
	char ent[100];
	scanf("%[^\n]s", ent);
	int size;
	int *ent_int = splitInt(ent,&size);
	if(ent_int == NULL){
		printf("String inválida\n");
		return -1;
	}
	printf("Size: %d\n", size);
	for(int i = 0; i < size; i++){
		printf("%d ",ent_int[i]);
	}
  return 0;
}