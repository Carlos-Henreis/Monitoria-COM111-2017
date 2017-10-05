//Arquivo ListaSequencial.h
#define MAX 100

typedef struct lista Lista;
Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, int *dado);
int consulta_lista(Lista* li, int mat, int dado);
int insere_lista_final(Lista* li, int dado);
int insere_lista_inicio(Lista* li, int dado);
int insere_lista_ordenada(Lista* li, int dado);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

int remove_lista_otimizado(Lista* li, int dado);
