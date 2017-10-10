#define TRUE 1
#define FALSE 0

typedef struct lista lista;
typedef struct no tno;

lista *create();
int isEmpty(lista *li);
int insert(lista *li, int d);
int removeL(lista *li, int d);
void imprime(lista *li);
int qtdElements (lista *li);