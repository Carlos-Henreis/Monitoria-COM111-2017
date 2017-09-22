#include "pilha.h"

int main(void) {
	int i;
	pilha_t p1;
	create(&p1);
	if (isEmpty(p1))
		printf("Pilha Vazia\n");
	else
		printf("Pilha com Dados\n");
	for(i=1;i<=4;i++)
		if (!push(&p1, i))
			exit(0);
		else
			printf("Dado %d inserido\n", i);		
	while(!isEmpty(p1)){
		pop(&p1,&i);
		printf("\n Pilha: %d", i);
	}
	return 0;
}