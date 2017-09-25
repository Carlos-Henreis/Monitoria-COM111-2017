//Arquivo fila_tDin.h

typedef struct fila fila_t;

fila_t* cria_fila();
void libera_fila(fila_t* fi);
int consulta_fila(fila_t* fi, int *dado);
int insere_fila(fila_t* fi, int dado);
int remove_fila(fila_t* fi);
int tamanho_fila(fila_t* fi);
int fila_vazia(fila_t* fi);
int fila_cheia(fila_t* fi);
void imprime_fila(fila_t* fi);


