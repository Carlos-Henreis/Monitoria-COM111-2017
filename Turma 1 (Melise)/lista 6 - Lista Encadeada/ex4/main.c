#include <stdio.h>
#include <stdlib.h>
#include "listaSEncadeada.h"


int main(void) {
	int i;

	lista *L = create();
	if (isEmpty(L))
		printf("Lista Vazia\n");
	else
		printf("Lista com Dados\n");

    
    for(i=3; i >= 0; i--)
        insert(L, i);
	
	imprime_lista(L);
	
		
	for(i=0; i < 4; i++){
		removeL(L, i);
		imprime_lista(L);
	}
	
	return 0;
}
