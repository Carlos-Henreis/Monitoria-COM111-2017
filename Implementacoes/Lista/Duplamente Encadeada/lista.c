#include <stdlib.h>

struct no_t {
	int dado;
	struct no_t *prox;
	struct no_t *ant;
};
struct listaDE {
	no_t *inicio;
	no_t *fim;
};

listaDE *create() {
	listaDE *q = (listaDE*) malloc (sizeof (listaDE));
	q->inicio=NULL;
	q->fim = NULL;
	return q;
}

int isEmpty(listaDE *q) {
	return (q->inicio == NULL);
}

int insert(listaDE *q, int d) {
	no_t *no = (no_t *) malloc(sizeof(no_t));
	if (!no) 
		return FALSE;
	no->dado = dado;
	if (isEmpty(q) {
		no->prox = no->ant = NULL;
		q->inicio = q->fim = no;
		return TRUE;
	}
	no->prox = NULL;
	q->fim->prox = no;
	no->ant = q->fim;
	q->fim = no;
	return TRUE;
}

void imprime(listaDE *q) {
	no_t *aux;
	if (isEmpty(q)) 
		return;
	aux = q->inicio;
	while (aux !=NULL) {
		printf("%d ", aux->dado);
		aux = aux->prox;
	}
}

int remove(listaDE *q, int d) {
	struct no *aux, *atual;
	if (d == q->fim->dado) {
		aux = q->fim;
		if (q->fim == q->inicio) {
			q->inicio = q->fim = NULL; 
		}
		else {
			q->fim = q->fim->ant;
			 q->fim->prox = NULL; 
		}
		free(aux);
		return TRUE;
	}

	atual = q->inicio;
	while (atual && atual->dado != d) {
		atual = atual->prox; 
	}
	if (!atual) 
		return FALSE;
	if (atual->ant == NULL) { // dado está no inicio
		q->inicio = q->inicio->prox; 
		q->inicio->ant = NULL; 
	}
	else {
		atual->ant->prox = atual->prox;
		atual->prox->ant = atual->ant;
	}
	free(atual);
	return(TRUE);
}