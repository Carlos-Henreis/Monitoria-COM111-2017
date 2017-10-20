#define TRUE 1
#define FALSE 0

typedef struct no no_t;
typedef struct listaCDE listaCDE;


listaCDE *cria_lista();
int isEmpty(listaCDE *q);
int insert(listaCDE *q, int d);
int remover(listaCDE *q, int *d);
void imprime(listaCDE *q);
void imprimeRecAux (no_t *inicio, no_t *fim);
void imprimeRec (listaCDE *l);