#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define INTEIRO 2
#define CARACTER 3
#define DECIMAL 4


typedef struct dado_t {
    void *d;
    int tam_dado;
    int tipo;
} dado_t;

typedef struct no {
	dado_t *dado;
	struct no *prox;
} no_t;

typedef struct pilha_t {
	no_t *topo;
} pilha_t;


#ifndef _PILHA_H
#define _PILHA_H

void create(pilha_t *p);
int isEmpty(pilha_t p); 
int push(pilha_t *p, void *d, int tamanho_d, int tipo);
int pop(pilha_t *p, dado_t *d);

#endif