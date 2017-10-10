#define TRUE 1
#define FALSE 0

typedef struct no tno;
typedef struct lista lista;

struct produto{
     int codigo; 
     char periculosidade;
     float preco;
};

lista *create();
int isEmpty(lista *li);
int insert(lista *li, struct produto p);
int removeL(lista *li, int codigo);
void imprime_lista(lista* li);
int consulta_lista_cod(lista* li, int codigo, struct produto *p);
void imprimeProd(lista *li, int codigo);
int qtdElementsP (lista *li, char periculosidade);