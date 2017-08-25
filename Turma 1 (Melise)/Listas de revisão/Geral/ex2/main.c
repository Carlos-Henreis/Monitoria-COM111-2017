#include <stdio.h>
#define V 1
#define F 0

void perfeito (int num, int *e_perfeito) {
	int i, soma = 0;
	for (i = 1; i < num; i++){
		if (num%i == 0){//Quer dizer que num é divissível por i
			soma += i;
		}
	}
	if (soma == num) {
		*e_perfeito = V;
	}else {
		*e_perfeito = F;
	}
}

int main(void){
	int num, e_perfeito;
	printf("Entre com o número\n");
	scanf (" %d", &num);
	perfeito (num, &e_perfeito);
	if (e_perfeito == V){
		printf("%d é perfeito\n", num);
	}else{
		printf("%d não é perfeito\n", num);
	}
	return 0;
}