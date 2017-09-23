#include "pilha.h"

/***
O TAD Pilha deve conter as seguintes funcionalidades:

create(&p): cria uma pilha vazia p

push (&p,v): empilha o valor da variável v na pilha p

pop(&p,&v) : desempilha da pilha p e retorna em v o valor do elemento que estava no topo da pilha p

top(p): retorna o valor do elemento do topo da pilha p, sem desempilhar esse elemento da pilha

isEmpty(p): s recebe TRUE (1) se a pilha p estiver vazia, e FALSE (0), caso contrário

imprimir_pilha (p): desempilha elementos da pilha e os imprime 

***/

void create(pilha_t *p){
	p->topo=NULL;
}

int isEmpty(pilha_t p) {
	if (p.topo == NULL)
		return TRUE;
	return FALSE;
}

int push(pilha_t *p, void *d, int tamanho_d, int tipo) {
	no_t *aux;
	aux = (no_t *)malloc(sizeof(no_t));
	if (aux == NULL) 
		return FALSE;
	aux->dado = (dado_t *) malloc (sizeof(dado_t));
	if (aux->dado == NULL){
		free(aux);
		return FALSE;
	}
	(aux->dado)->d = malloc (tamanho_d);
	if ((aux->dado)->d == NULL){
		free(aux->dado);
		free(aux);
		return FALSE;
	}
	
	memcpy ((aux->dado)->d, d, tamanho_d);
	(aux->dado)->tam_dado = tamanho_d;
	(aux->dado)->tipo = tipo;
	aux->prox = p->topo;
	p->topo = aux;
	return TRUE;

}


int pop(pilha_t *p, dado_t *d) {
	no_t *aux;
	if (p->topo == NULL) 
		return FALSE;
	aux= p->topo;
	p->topo =(p->topo)->prox;
	memcpy(d, (aux)->dado, sizeof(dado_t));
	free(aux);
	return(TRUE);
}
