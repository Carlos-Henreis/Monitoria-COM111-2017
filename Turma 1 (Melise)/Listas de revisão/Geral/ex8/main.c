#include <stdio.h>

#define TAMMAX 4//Mudar aqui se quiser aumentar o qtd de cidades
#define CAMMAX 15

int custoEt (int matrix[][TAMMAX], int *caminho, int tam) {
	int i;
	int total= 0;
	for (i =0; i< tam-1; i++) {
		total += matrix[caminho[i]][caminho[i+1]];
	}
	return total;
}

int main (void) {
	int matrix[TAMMAX][TAMMAX] = {{4, 1, 2, 3}, {5, 2, 1, 400}, {2, 1, 3, 8}, {7, 1, 2, 5}};
	int caminho[CAMMAX];
	int tam = 0, cidade;
	char teste;
	do {
		printf ("Entre com o valor\n");
		scanf (" %d", &cidade);
		printf ("Deseja contnuar (s/n)\n");
		scanf (" %c", &teste);
		if (((teste != 's') && (teste != 'n')) || ((cidade > 3) || (cidade<0))){
			printf ("Entre com o dado correto malandro\n");
		}else {
			caminho[tam] = cidade;
			tam+=1;
		}
	}while (tam<15 && (teste != 'n'));
	printf ("%d", custoEt(matrix, caminho, tam));
	return 0;
}
