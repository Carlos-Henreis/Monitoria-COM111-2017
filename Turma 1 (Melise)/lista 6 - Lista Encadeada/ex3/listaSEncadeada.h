#define TRUE 1
#define FALSE 0
#define TAMNOME 101
#define TAMEND 201
#define TAMDATA 11

typedef struct no tno;
typedef struct lista lista;

struct cliente{
     int codigo; 
     char nome[TAMNOME];
     char endereco [TAMEND];
     char dUltCompra[TAMDATA];
     char dataNas[TAMDATA];
};

lista *create();
int isEmpty(lista *li);
int insert(lista *li, struct cliente c);
int removeL(lista *li, int codigo);
void imprime_lista(lista* li);