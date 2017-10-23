#define TRUE 1
#define FALSE 0

typedef struct no no_t;

typedef struct listaC listaC;

listaC *create();
int isEmpty(listaC *q);
int insert(listaC *q, int d);
int remover(listaC *q, int d);
void imprime(listaC *q);