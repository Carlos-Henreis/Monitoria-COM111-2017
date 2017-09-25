#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"
int main(){
    int dado= 10;

    fila_t* fi = cria_Fila();
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    int i;
    for(i=0; i < 4; i++){
        dado += 12*i;
        insere_Fila(fi,dado);
        consulta_Fila(fi, &dado);
        printf("Consulta: %d\n",dado);
    }

    imprime_Fila(fi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));

    for(i=0; i < 2; i++){
        remove_Fila(fi);
        consulta_Fila(fi,&dado);
        printf("Consulta: %d\n",dado);
    }
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    for(i=0; i < 4; i++){
        dado += 120-i;
        insere_Fila(fi, dado);
    }

    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    libera_Fila(fi);
    return 0;
}


