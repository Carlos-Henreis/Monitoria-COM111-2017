#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct no {
	int dado;
	struct no *prox;
};

struct listaC{
	struct no *inicio;
	struct no *fim;
};


listaC *create() {
	listaC *q = (listaC*) malloc (sizeof (listaC));
	q->inicio=NULL;
	q->fim = NULL;
	return q;
}

int isEmpty(listaC *q) {
	return (q->inicio == NULL);
}

int insert(listaC *l, int d) {
	no_t *aux, *ant, *atual;
	aux = malloc(sizeof(struct no));
	if (!aux) 
		return FALSE;
	aux->dado = d;
	if (isEmpty(l)){ //lista vazia
		l->inicio = aux;
		l->fim = aux;
		l->fim->prox = l->inicio;
		return TRUE;
	}
	ant = NULL;
	atual = l->inicio;
	while (ant != l->fim && atual->dado > d){
		ant = atual;
		atual = atual->prox;
	}
	if (ant == NULL){ // insere antes do inicio
		aux->prox = l->inicio;
		l->inicio = aux;
	} else {
		if (ant == l->fim) { // insere depois do fim
			l->fim->prox = aux;
			l->fim = aux;
		} 
		else { // insere no meio
			ant->prox = aux;
			aux->prox = atual;
		}
	}
	l->fim->prox = l->inicio;
	return TRUE;
}

void imprime(listaC *q) {
	no_t *aux;
	if (isEmpty(q)) 
		return;
	aux = q->inicio;
	while (aux != q->fim) {
		printf("%d-> ", aux->dado);
		aux = aux->prox;
	}
	printf("%d\n", aux->dado);
}

int remover(listaC *l, int d) {
	no_t *ant, *atual;
	ant = NULL;
	atual = l->inicio;
	while (ant != l->fim && atual->dado != d){
		ant = atual;
		atual = atual->prox;
	}
	if (ant == l->fim) 
		return FALSE; // não encontrou o dado
	if (atual == l->inicio){ // dado encontrado no inicio
		if (l->inicio == l->fim) { // inicio igual ao fim
			l->inicio = NULL;
			l->fim = NULL;
		} 
		else { // ajusta ponteiro de inicio
			l->inicio = l->inicio->prox;
			l->fim->prox = l->inicio;
		}
	} 
	else {
		if (atual == l->fim){ // dado encontrado no fim
			l->fim = ant;
			l->fim->prox = l->inicio;
		} 
		else { // dado encontrado no meio
			ant->prox = atual->prox;
		}
	}
	free(atual);
	return TRUE;
}