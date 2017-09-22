#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define TAM_PILHA 10
#define VAZIA -1

typedef struct stack_t{
	int itens[TAM_PILHA];
	int topo;
} pilha_t;

#ifndef _PILHA_H
#define _PILHA_H

void create(pilha_t *p);
int isEmpty(pilha_t p); 
int push(pilha_t *p, int d);
int pop(pilha_t *p, int *d);
void imprimir_pilha (pilha_t p);


#endif