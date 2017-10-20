#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct no {
	int dado;
	struct no *prox;
};

struct listaCDE{
	no_t *inicio;
	no_t *fim;
};


listaCDE *create() {
	listaCDE *q = (listaCDE*) malloc (sizeof (listaCDE));
	q->inicio=NULL;
	q->fim = NULL;
	return q;
}

int isEmpty(listaCDE *q) {
	return (q->inicio == NULL);
}

no_t *cria_no(int dado) {
	no_t *no = (no_t *)malloc(sizeof(no_t));
	if (!no) 
		return NULL;
	no->dado = dado;
	no->ant = no->prox = NULL;
	return no;
}

int insert(listaCDE *l, int d) {
	no_t *no = cria_no(dado);
	if (!no) 
		return FALSE;

	if (isEmpty(l)) {
		l->inicio = l->fim = no;
		no->prox = no->ant = no;
		return TRUE;
	}
	no->prox = l->inicio;
	l->inicio->ant = no;
	l->inicio = no;
	l->inicio->ant = l->fim;
	l->fim->prox = l->inicio;
	return TRUE;
}

void imprime(listaCDE *q) {
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

void imprimeRec (listaCDE *q) {
	printf("%d-> ", q->inicio->dado);
	if (isEmpty(q)) 
		return;
	if (q->inicio != q->fim)
		return;
	imprimeRec (q->inicio->prox);
	printf("%d\n", q->fim->dado);
}



int remover(listaCDE *l, int *dado) {
	no_t *no = l->inicio;
	if (isEmpty(l)) 
		return FALSE;
	*dado = l->inicio->dado;
	if (l->inicio == l->fim) {// um elemento
		l->inicio = l->fim = NULL;
	}
	else {
		l->inicio = l->inicio->prox;
		l->inicio->ant = l->fim;
		l->fim->prox = l->inicio;
	}
	free(no);
	return TRUE;
}