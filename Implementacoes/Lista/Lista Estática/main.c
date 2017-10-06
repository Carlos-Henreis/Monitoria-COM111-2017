#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
int main(){
   
    Lista *li = cria_lista(); 
    int i;
    for(i=4; i > 0; i--)
        insere_lista_ordenada(li, i);

    imprime_lista(li);
    printf("\n\n\n\n");

    for(i=0; i < 5; i++){
        if (!remove_lista_otimizado(li,i))
            printf("Erro\n");

        imprime_lista(li);
        printf("\n\n\n\n");
    }

    libera_lista(li);
    return 0;
}

