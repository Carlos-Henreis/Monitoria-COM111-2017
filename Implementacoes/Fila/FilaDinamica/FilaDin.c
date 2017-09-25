#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Protótipos
//Definição do tipo fila_t
struct no{
    int dado;
    struct no *prox;
};
typedef struct no no_t;
//Definição do Nó Descritor da fila_t
struct fila{
    no_t *inicio;
    no_t *final;
    int qtd;
};

fila_t* cria_fila(){
    fila_t *fi;
    fi = (fila_t*) malloc(sizeof(fila_t));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(fila_t* fi){
    if(fi != NULL){
        no_t *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_fila(fila_t* fi, int *dado){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *dado = fi->inicio->dado;
    return 1;
}

int insere_fila(fila_t* fi, int dado){
    if(fi == NULL)
        return 0;
    no_t *no = (no_t*) malloc(sizeof(no_t));
    if(no == NULL)
        return 0;
    no->dado = dado;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_fila(fila_t* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    no_t *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_fila(fila_t* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int fila_vazia(fila_t* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int fila_cheia(fila_t* fi){
    return 0;
}

void imprime_fila(fila_t* fi){
    if(fi == NULL)
        return;
    no_t *no = fi->inicio;
    while(no != NULL){
        printf("%d\t", no->dado);
        no = no->prox;
    }
}
