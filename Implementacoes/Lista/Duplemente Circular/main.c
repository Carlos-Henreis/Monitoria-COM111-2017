#include "lista.h"
#include <stdio.h>

int main(void) {
	listaCDE *l;
	int d;
	l = cria_lista();
	insere(l,12);
	insere(l,12);
	insere(l,320);
	insere(l,413);
	insere(l,197);
	insere(l,26);
	imprimeRec(l);
	if (retira(&l, &d)){
		printf("dado removido %d\n", d);
	}

	imprimeRec(l);
	return 0;
}