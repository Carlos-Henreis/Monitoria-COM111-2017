#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h" //inclui os Protótipos

//Definição do tipo lista
struct lista{
    int qtd;
    int dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int consulta_lista_pos(Lista* li, int pos, int *dado){
    if(li == NULL || pos <= 0 ||  pos > li->qtd)
        return 0;
    *dado = li->dados[pos-1];
    return 1;
}

int consulta_lista_(Lista* li, int mat, int dado){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i] != dado)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    return 1;
}

int insere_lista_final(Lista* li, int dado){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    li->dados[li->qtd] = dado;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, int dado){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = dado;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, int dado){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i] < dado)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista(Lista* li, int dado){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i] != dado)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_otimizado(Lista* li, int dado){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i] != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i;
    for(i=0; i< li->qtd; i++){
        printf("%d->\n",li->dados[i]);
    }
}
