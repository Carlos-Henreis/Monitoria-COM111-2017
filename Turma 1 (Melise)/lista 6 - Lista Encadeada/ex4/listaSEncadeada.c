#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSEncadeada.h" //inclui os Protótipos

struct no {
	int dado;
	struct no *prox;
};

 
struct lista{
	tno com;
};

lista *create() {
	lista *li;
    li = (lista*) malloc(sizeof(lista));
    if(li != NULL){
        li->com.dado = 0;
        li->com.prox = NULL;
    }
    return li;
}


int isEmpty(lista *li) {
	if (li->com.prox == NULL && li->com.dado == 0)
		return TRUE;
	return FALSE;
}

int insert(lista *li, int dado) { // insercao ordenada
	tno *ant, *atual, *aux;
	aux = (tno*) malloc(sizeof(tno));
	if (!aux) 
		return FALSE;
	
	aux->dado = dado;
	aux->prox = NULL;
	
	if (li->com.prox == NULL) {
		li->com.prox = aux;
	}else{
		if (dado < li->com.prox->dado) {
			aux->prox = li->com.prox;
			li->com.prox = aux;
		}else{
			ant = atual = li->com.prox;
			
			while ((atual != NULL) && (dado >= atual->dado)) {
				ant = atual;
				atual = atual->prox;
			}
			aux->prox = ant->prox;
			ant->prox = aux;
		}
	}
	li->com.dado ++;
	return TRUE;
}

int removeL(lista *li, int dado) {
	tno *ant = NULL,
	*atual = li->com.prox;
	while ((atual) && (atual->dado != dado)){
		ant = atual;
		atual = atual->prox;
	}
	if (!atual) 
		return FALSE;
	if (atual == li->com.prox)
		li->com.prox = atual->prox;
	else
		ant->prox = atual->prox;
	free(atual);
	li->com.dado--;
	return TRUE;
}

void imprime_lista(lista* li){
    if(isEmpty(li)){
        printf("não existem elementos na lista\n");
        return;
    }
    tno* no = li->com.prox;
    printf("Quantidade de elementos %d\n", li->com.dado);
    while(no != NULL){
        printf("%d->",no->dado);
        no = no->prox;
    }
    printf("\n----------------------\n");
}



