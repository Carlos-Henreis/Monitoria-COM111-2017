#include <stdio.h>
#include <stdlib.h>
#include "listaSEncadeada.h" //inclui os Protótipos

struct no {
	produto dado;
	struct no *prox;
};

struct lista{
	struct no *inicio;
	int qtd;
};

lista *create() {
	lista *li;
    li = (lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
        li->inicio = NULL;
    }
    return li;
}


int isEmpty(lista *li) {
	if (li->inicio == NULL && li->qtd == 0)
		return TRUE;
	return FALSE;
}

int insert (lista *li, int d) { // insercao ordenada
	struct no *ant, *atual, *aux;
	aux = (struct no *)calloc(1, sizeof(struct no));
	if (!aux) 
		return FALSE;
	
	aux->dado = d;
	aux->prox = NULL;
	
	if (li->inicio == NULL) {
		li->inicio = aux;
		return TRUE;
	}
	if (d < li->inicio->dado) {
		aux->prox = li->inicio;
		li->inicio = aux;
		return TRUE;
	}
	ant = atual = li->inicio;
	
	while (atual != NULL && d >= atual->dado) {
		ant = atual;
		atual = atual->prox;
	}
	aux->prox = ant->prox;
	ant->prox = aux;
	li->qtd++;
	return TRUE;
}

int removeL (lista *li, int d) {
	struct no *ant = NULL,
	*atual = li->inicio;
	while (atual && atual->dado != d){
		ant = atual;
		atual = atual->prox;
	}
	if (!atual) 
		return FALSE;
	if (atual == li->inicio)
		li->inicio = atual->prox;
	else
		ant->prox = atual->prox;
	free(atual);
	li->qtd--;
	return TRUE;
}

void imprime (lista *li) {
	struct no *aux = li->inicio;
	while (aux != NULL) {
		printf("%d->", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
	return;
}

int qtdElements (lista *li) {
	if (!li)
		return -1;
	return li->qtd;
}