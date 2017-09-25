//Arquivo FilaEstatica.h
#define MAX 100

typedef struct fila fila_t;

fila_t* cria_Fila();
void libera_Fila(fila_t* fi);
int consulta_Fila(fila_t* fi, int *dado);
int insere_Fila(fila_t* fi, int dado);
int remove_Fila(fila_t* fi);
int tamanho_Fila(fila_t* fi);
int Fila_vazia(fila_t* fi);
int Fila_cheia(fila_t* fi);
void imprime_Fila(fila_t* fi);

