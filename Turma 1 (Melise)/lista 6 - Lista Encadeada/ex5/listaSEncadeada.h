#define TRUE 1
#define FALSE 0


typedef struct no tno;


int isEmpty(tno *com);
tno *insert(tno *com, int dado, int *c);
tno *removeL(tno *com, int dado, int *c);
void imprime_lista(tno *com);