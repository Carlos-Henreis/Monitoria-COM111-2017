#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSEncadeada.h" //inclui os Protótipos

struct no {
	struct cliente c;
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

int insert(lista *li, struct cliente c) { // insercao ordenada
	tno *ant, *atual, *aux;
	aux = (tno*) malloc(sizeof(tno));
	if (!aux) 
		return FALSE;
	
	aux->c = c;
	aux->prox = NULL;
	
	if (li->com == NULL) {
		li->com = aux;
	}else{
		if (strcmp(c.nome, li->com->c.nome)<= 0) {
			aux->prox = li->com;
			li->com = aux;
		}else{
			ant = atual = li->com;
			
			while ((atual != NULL) && (strcmp (c.nome, atual->c.nome)>= 0)) {
				ant = atual;
				atual = atual->prox;
			}
			aux->prox = ant->prox;
			ant->prox = aux;
		}
	}
	li->qtd++;
	return TRUE;
}

int removeL(lista *li, int codigo) {
	tno *ant = NULL,
	*atual = li->com;
	while ((atual) && (atual->c.codigo != codigo)){
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
    if(isEmpty(li)){
        printf("não existem elementos na lista\n");
        return;
    }
    tno* no = li->com;
    while(no != NULL){
        printf("codigo: %d\n",no->c.codigo);
        printf("nome: %s\n",no->c.nome);
        printf("endereco: %s\n",no->c.endereco);
        printf("data ultima compra: %s\n",no->c.dUltCompra);
        printf("data de nascimento: %s\n",no->c.dataNas);

        printf("-------------------------------\n");

        no = no->prox;
    }
    printf("\n\n\n\n\n");
}



