#include <stdio.h>
#include <stdlib.h>
#include "listaSEncadeada.h"


int main(void) {
	int i;
	struct produto p[4] = {{3,'S',9.5},
                           {1,'R',7.5},
                           {4,'S',9.7},
                           {2,'S',5.7}};

	lista *L = create();
	if (isEmpty(L))
		printf("Lista Vazia\n");
	else
		printf("Lista com Dados\n");

    
    for(i=0; i < 4; i++)
        insert(L, p[i]);
	
	imprime_lista(L);
	
	printf("\n\n\n\n quantidde de periculosidade S: %d\n", qtdElementsP(L, 'S'));
	imprimeProd(L, 12);
	imprimeProd(L, 3);
	for(i=0; i < 4; i++){
		removeL(L, p[i].codigo);
		imprime_lista(L);
	}
	
	return 0;
}
