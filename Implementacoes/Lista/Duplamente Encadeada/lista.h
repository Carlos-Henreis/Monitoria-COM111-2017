#define TRUE 1
#define FALSE 0

typedef struct no_t no_t;

typedef struct listaDE listaDE;

listaDE *create();
int isEmpty(listaDE *q);
int insert(listaDE *q, int d);
int remover(listaDE *q, int d);
void imprime(listaDE *q);
