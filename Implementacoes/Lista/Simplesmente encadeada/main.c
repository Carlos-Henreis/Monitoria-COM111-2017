#include <stdio.h>
#include "listaSEncadeada.h"


int main(void) {
	lista *L = create();
	if (isEmpty(L))
		printf("Lista Vazia\n");
	else
		printf("Lista com Dados\n");
	
	insert(L,12);
	insert(L,320);
	insert(L,197);
	insert(L,26);
	
	imprime(L);
	
	removeL(L,320);
	
	imprime(L);
	
	return 0;
}