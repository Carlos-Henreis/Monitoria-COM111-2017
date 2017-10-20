#include "lista.h"
#include <stdio.h>

int main(void) {
	listaC *f;
	f = create();
	if (isEmpty(f))
		printf ("Lista Circular Vazia\n");
	else
		printf("Lista Circular com Dados\n");
	insert(f,12);
	insert(f,320);
	insert(f,413);
	insert(f,197);
	insert(f,26);
	imprime(f);
	remover(f,320);
	imprime(f);
	return 0;
}