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

void create(pilha_t *p) {
	p->topo = VAZIA;
	return;
}

int isEmpty(pilha_t p) {
	if (p.topo==VAZIA)
		return TRUE;
	return FALSE;
}

int push(pilha_t *p, int d) {
	if (p->topo==TAM_PILHA-1)
		return FALSE;
	p->topo++;
	p->itens[p->topo]=d;
	return TRUE;
}

int pop(pilha_t *p, int *d) {
	if (isEmpty(*p))
		return FALSE;
	*d = p->itens[p->topo];
	p->topo--;
	return TRUE;
}

void imprimir_pilha (pilha_t p){

    int i, recebe;
    
    printf("OS ELMENTOS DA PILHA\n");
    while(p.topo != VAZIA){
        if(!pop(&p, &recebe))
            printf("A PILHA ESTA vazia\n");
        printf("%d\n",recebe);
    }
   return;
}