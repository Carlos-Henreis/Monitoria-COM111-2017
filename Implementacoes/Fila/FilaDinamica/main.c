#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main(){
    int dado = 10;
    fila_t* fi = cria_fila();
    printf("Tamanho: %d\n\n\n\n",tamanho_fila(fi));
    int i;
    for(i=0; i < 4; i++){
        dado += i+((dado+i)/dado);
        insere_fila(fi,dado);
        if(fila_vazia(fi))
            printf("Erro!!!!!!\n");

        consulta_fila(fi,&dado);
        printf("Consulta: %d\n",dado);
    }

    imprime_fila(fi);
    printf("Tamanho: %d\n\n\n\n",tamanho_fila(fi));

    for(i=0; i < 2; i++){
        remove_fila(fi);
        consulta_fila(fi,&dado);
        printf("Consulta: %d\n", dado);
    }
    printf("Tamanho: %d\n\n\n\n",tamanho_fila(fi));
    imprime_fila(fi);

    for(i=0; i < 4; i++){
        dado+=i*23;
        insere_fila(fi, dado);
    }
    printf("Tamanho: %d\n\n\n\n",tamanho_fila(fi));
    imprime_fila(fi);

    libera_fila(fi);
    return 0;
}


