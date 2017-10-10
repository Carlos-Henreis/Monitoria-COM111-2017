#define TRUE 1
#define FALSE 0
#define TAMNOME 101
#define TAMEND 201
#define TAMDATA 11

typedef struct no tno;
typedef struct lista lista;


lista *create();
int isEmpty(lista *li);
int insert(lista *li, int dado);
int removeL(lista *li, int dado);
void imprime_lista(lista* li);