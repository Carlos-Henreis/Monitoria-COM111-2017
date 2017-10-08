
1. Observe o código abaixo:

```c
void incluiLista(tlista *l, int info) {
	tno *p, *aux, *ant;
	p = (tno*)malloc(sizeof(tno));
	if (!p) printf("\n Nao tem memoria \n");
	else {
		aux = l->com;
		ant = (tno *) NULL;
		while ((aux) && (aux->dado < info)) {
			ant = aux;
			aux = aux->prox;
		}
		p-> dado = info;
		if (!ant) {
			p->prox = l->com;
			l->com = p;
		}
		else {
			ant->prox = p;
			p->prox = aux;
		}
	}
}
// ...
```


Responda as seguintes perguntas:

a) No cabeçalho da função incluiLista, a lista l foi passada como referência. Justifique a passagem da lista por referência nesta função.

b) Na atribuição aux = l->com, por que não podemos usar l.com já que com é um campo da lista l?

c) Considere uma lista de inteiros com os seguintes valores de dados: 5,8,12,85. Para cada chamada da função e para cada iteração do loop destacado em vermelho, escreva os valores de ant->dado e aux->dado assumidos durante a execução do algoritmo.



##Resposta exercio 1:

a.  Neste caso é necessário passar a lista l por referencia, pois pode-se haver uma alteração em seu conteúdo como o seu começo (ponteiro com aṕonta para outro no que se tornou inicio da lista).

b.  Isso não é possivel pois a lista l foi passada por referencia e não por valor. Isso gerará o erro, a sintaxe correta deve ser b->x ou (*b).x 

c. 

1. `incluiLista (&l, 5)`
   * aux = l->com == NULL
   * ant == NULL
   1. Laço-> NEm entra aux == NULL
   * logo aux->dado e ant->dado não existem
2. `incluiLista (&l, 8)`
   * aux = l->com
   * ant == NULL
   1. Laço
      * ant == aux
      * aux == NULL
         * ant->dado == 5 e aux->dado não existe
   * Sai do laco 
3. `incluiLista (&l, 12)`
   * aux = l->com
   * ant == NULL
   1. Laço
      * ant == aux
      * aux == aux->prox
         * ant->dado == 5 e aux->dado == 8
   2. Laço
      * ant == aux
      * aux == aux->prox
         * ant->dado == 8 e aux->dado == não existe
      * Sai do laco 
4. `incluiLista (&l, 85)`
   * aux = l->com
   * ant == NULL
   1. Laço
      * ant == aux
      * aux == aux->prox
         * ant->dado == 5 e aux->dado == 8
   2. Laço
      * ant == aux
      * aux == aux->prox
         * ant->dado == 8 e aux->dado == 12
   3. Laço
      * ant == aux
      * aux == aux->prox
         * ant->dado == 12 e aux->dado não existe
      * Sai do laco
