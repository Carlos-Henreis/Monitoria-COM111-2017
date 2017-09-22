#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef struct no {
	int dado;
	struct no *prox;
} no_t;

typedef struct pilha_t {
	no_t *topo;
} pilha_t;


#ifndef _PILHA_H
#define _PILHA_H

void create(pilha_t *p);
int isEmpty(pilha_t p); 
int push(pilha_t *p, int d);
int pop(pilha_t *p, int *d);


#endif