#include <stdio.h>

#define TAMMAX 4//Mudar aqui se quiser aumentar o qtd de cidades
#define CAMMAX 8

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
	int caminho[CAMMAX] = {0, 3, 1, 3, 3, 2, 1, 0};
	int tam = 8;

	printf ("%d", custoEt(matrix, caminho, tam));
	return 0;
}
