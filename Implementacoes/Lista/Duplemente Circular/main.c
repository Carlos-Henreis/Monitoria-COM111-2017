#include "lista.h"
#include <stdio.h>

int main(void) {
	listaCDE *l;
	int d;
	l = cria_lista();
	insert(l,12);
	insert(l,320);
	insert(l,413);
	insert(l,197);
	insert(l,26);
	imprimeRec(l);
	if (remover(l, &d)){
		printf("dado removido %d\n", d);
	}

	imprimeRec(l);
	return 0;
}