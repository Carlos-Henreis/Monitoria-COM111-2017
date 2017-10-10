#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSEncadeada.h" //inclui os Protótipos

struct no {
	int dado;
	struct no *prox;
};

int isEmpty(tno *com) {
	if (com == NULL)
		return TRUE;
	return FALSE;
}


tno *insert(tno *com, int dado, int *c) { // insercao ordenada
	tno *ant, *atual, *aux;
	aux = (tno*) malloc(sizeof(tno));
	if (!aux){
		*c = FALSE;
		return com;
	}
	
	aux->dado = dado;
	aux->prox = NULL;
	
	if (com == NULL) {
		com = aux;
	}else{
		if (dado < com->dado) {
			aux->prox = com;
			com = aux;
		}else{
			ant = atual = com;
			while ((atual != NULL) && (dado >= atual->dado)) {
				ant = atual;
				atual = atual->prox;
			}
			aux->prox = ant->prox;
			ant->prox = aux;
		}
	}
	*c = TRUE;
	return com;
}

tno *removeL(tno *com, int dado, int *c) {
	tno *ant = NULL,
	*atual = com;
	while ((atual) && (atual->dado != dado)){
		ant = atual;
		atual = atual->prox;
	}
	if (!atual){ 
		*c = FALSE;
		return com;
	}
	if (atual == com)
		com = atual->prox;
	else
		ant->prox = atual->prox;
	free(atual);
	*c = TRUE;
	return com;
}

void imprime_lista(tno* com){
    if(isEmpty(com)){
        printf("não existem elementos na lista\n");
        return;
    }
    tno* no = com;
    while(no != NULL){
        printf("%d->",no->dado);
        no = no->prox;
    }
    printf("\n----------------------\n");
}



