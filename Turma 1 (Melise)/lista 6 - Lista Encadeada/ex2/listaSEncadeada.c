#include <stdio.h>
#include <stdlib.h>
#include "listaSEncadeada.h" //inclui os Protótipos

struct no {
	struct produto p;
	struct no *prox;
};


struct lista{
	tno *com;
	int qtd;
};

lista *create() {
	lista *li;
    li = (lista*) malloc(sizeof(lista));
    if(li != NULL){
        li->qtd = 0;
        li->com = NULL;
    }
    return li;
}


int isEmpty(lista *li) {
	if (li->com == NULL && li->qtd == 0)
		return TRUE;
	return FALSE;
}

int insert(lista *li, struct produto p) { // insercao ordenada
	tno *ant, *atual, *aux;
	aux = (tno*) malloc(sizeof(tno));
	if (!aux) 
		return FALSE;
	
	aux->p = p;
	aux->prox = NULL;
	
	if (li->com == NULL) {
		li->com = aux;
		return TRUE;
	}
	if (p.codigo < li->com->p.codigo) {
		aux->prox = li->com;
		li->com = aux;
		return TRUE;
	}
	ant = atual = li->com;
	
	while (atual != NULL && p.codigo >= atual->p.codigo) {
		ant = atual;
		atual = atual->prox;
	}
	aux->prox = ant->prox;
	ant->prox = aux;
	li->qtd++;
	return TRUE;
}

int removeL(lista *li, int codigo) {
	tno *ant = NULL,
	*atual = li->com;
	while ((atual) && (atual->p.codigo != codigo)){
		ant = atual;
		atual = atual->prox;
	}
	if (!atual) 
		return FALSE;
	if (atual == li->com)
		li->com = atual->prox;
	else
		ant->prox = atual->prox;
	free(atual);
	li->qtd--;
	return TRUE;
}

void imprime_lista(lista* li){
    if(li == NULL)
        return;
    tno* no = li->com;
    while(no != NULL){
        printf("codigo: %d\n",no->p.codigo);
        printf("periculosidade: %c\n",no->p.periculosidade);
        printf("preco: %f\n",no->p.preco);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

int consulta_lista_cod(lista* li, int codigo, struct produto *p){
    if(li == NULL)
        return FALSE;
    tno *no = li->com;
    while(no != NULL && no->p.codigo != codigo){
        no = no->prox;
    }
    if(no == NULL)
        return FALSE;
    else{
        *p = no->p;
        return TRUE;
    }
}

void imprimeProd(lista *li, int codigo){
    struct produto *p = NULL;
    if (!consulta_lista_cod(li, codigo, p)){
    	printf("Nenhum produto como código passado\n");
    	return;
    }

    printf("codigo: %d\n",p->codigo);
    printf("periculosidade: %c\n",p->periculosidade);
    printf("preco: %f\n",p->preco);
    printf("-------------------------------\n");

    return;
}

int qtdElementsP (lista *li, char periculosidade) {
	int qtd = 0;
	if (!li)
		return -1;
	tno* no = li->com;
    while(no != NULL){
    	if (no->p.periculosidade == periculosidade) {
    		qtd++;
    	}
        no = no->prox;
    }
	return qtd;
}

