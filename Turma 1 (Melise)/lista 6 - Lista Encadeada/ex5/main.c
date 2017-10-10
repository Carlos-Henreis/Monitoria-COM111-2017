#include <stdio.h>
#include <stdlib.h>
#include "listaSEncadeada.h"


int main(void) {
	int i, controle = FALSE;

	tno *com = NULL;
	if (isEmpty(com))
		printf("Lista Vazia\n");
	else
		printf("Lista com Dados\n");

    
    for(i=3; i >= 0; i--){
        com = insert(com, i, &controle);
        if (controle) {
        	printf("Dados %d inserido\n", i);
        }
    }
	
	imprime_lista(com);
	removeL(com, 2, &controle);
	for(i=0; i < 4; i++){
		com = removeL(com, i, &controle);
		if (controle) {
        	printf("Dados %d removido\n", i);
        }
		imprime_lista(com);
	}
	
	return 0;
}
