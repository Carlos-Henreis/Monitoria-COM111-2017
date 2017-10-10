#include <stdio.h>
#include <stdlib.h>
#include "listaSEncadeada.h"


int main(void) {
	int i;

	struct cliente a[4] = {{3,"Carlos Henrique","Pedralva mg", "12/12/2016", "03/05/1995"},
                           {1,"Ana Silva","Itajubá mg", "12/09/2011", "25/11/1980"},
                           {4,"Leticia Sousa","Pedralva mg", "12/01/2017", "27/12/1995"},
                           {2,"Joao","Itajubá mg", "12/02/2016", "07/07/1961"}};

	lista *L = create();
	if (isEmpty(L))
		printf("Lista Vazia\n");
	else
		printf("Lista com Dados\n");

    
    for(i=0; i < 4; i++)
        insert(L, a[i]);
	
	imprime_lista(L);
	
		
	for(i=0; i < 4; i++){
		removeL(L, a[i].codigo);
		imprime_lista(L);
	}
	
	return 0;
}
