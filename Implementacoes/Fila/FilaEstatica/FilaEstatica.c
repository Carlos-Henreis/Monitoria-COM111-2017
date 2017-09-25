#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h" //inclui os Protótipos

//Definição do tipo Fila
struct fila{
    int inicio, final;
    int fila[MAX];
};

fila_t* cria_Fila(){
    fila_t *fi;
    fi = (fila_t*) malloc(sizeof(fila_t));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
    }
    return fi;
}

void libera_Fila(fila_t* fi){
    free(fi);
}

int consulta_Fila(fila_t* fi, int *dado){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    int pos = (fi->inicio+1)%MAX;//Lembre que a fila é circular
    *dado = fi->fila[pos];
    return 1;
}

int insere_Fila(fila_t* fi, int dado){
    if((fi == NULL) || (Fila_cheia(fi)))
        return 0;
    fi->final = (fi->final+1)%MAX;
    fi->fila[fi->final] = dado;
    return 1;
}

int remove_Fila(fila_t* fi){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    return 1;
}

int tamanho_Fila(fila_t* fi){
    if(fi == NULL)
        return -1;
    int qtd = abs(fi->final - fi->inicio);//A
    return qtd;
}

int Fila_cheia(fila_t* fi){
    if(fi == NULL)
        return -1;
    if (fi->inicio == (fi->final+1)%MAX)
        return 1;
    else
        return 0;
}

int Fila_vazia(fila_t* fi){
    if(fi == NULL)
        return -1;
    return (fi->inicio == fi->final);
}

void imprime_Fila(fila_t* fi){
    if(fi == NULL)
        return;
    int i = fi->inicio;
    while(i != fi->final){
        i = (i + 1) % MAX;
        printf("Dado: %d\n",fi->fila[i]);
    }
}
