#include <stdio.h>
#include "pilha.h"

int main(void) {
	int i;
	pilha_t p1;
	create(&p1);

	if (isEmpty(p1))
		printf("\n pilha vazia");
	else
		printf("\n pilha com dados");
	for(i=1;i<=4;i++) {
		if (push(&p1,i))
			printf("\n conseguiu empilhar %d", i);
		else
			printf("processo inválido %d", i);
	}

	imprimir_pilha (p1);

	while(!isEmpty(p1)){
		pop(&p1,&i);
		printf("\n desempilha: %d", i);
	}
	return 0;
}