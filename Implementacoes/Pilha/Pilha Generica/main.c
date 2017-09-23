#include "pilha.h"

int main(void) {
	int i;
	char c = 'a';
	float h = 12.2;
	dado_t aux;
	pilha_t p1;
	create(&p1);
	if (isEmpty(p1))
		printf("Pilha Vazia\n");
	else
		printf("Pilha com Dados\n");

	for(i=1;i<=4;i++) {
		if (!push(&p1, &i, sizeof(i), INTEIRO))
			exit(0);
		else
			printf("Dado %d inserido\n", i);
		c+=1;
		if (!push(&p1, &c, sizeof(c), CARACTER))
			exit(0);
		else
			printf("Dado %c inserido\n", c);	
		h+=i;
		if (!push(&p1, &h, sizeof(h), DECIMAL))
			exit(0);
		else
			printf("Dado %f inserido\n", h);	


	}
	while(!isEmpty(p1)){
		pop(&p1, &aux);
		if (aux.tipo == INTEIRO){
			memcpy(&i, aux.d, aux.tam_dado);
			printf("\n Pilha: %d", i);
		}else {
			if (aux.tipo == CARACTER) {
				memcpy(&c, aux.d, aux.tam_dado);
				printf("\n Pilha: %c", c);
			}else {
				memcpy(&h, aux.d, aux.tam_dado);  
				printf("\n Pilha: %f", h);
			}
		}

	}
	return 0;
}