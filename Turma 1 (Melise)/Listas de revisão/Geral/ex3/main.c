#include <stdio.h>
#include <string.h>
#define V 1
#define F 0
#define TAMARCA 15
#define TAMCOR 10
#define TAMVET 20

typedef struct carro{
	char marca[TAMARCA];
	int ano;
	char cor[TAMCOR];
	float preco;
}t_carro;

void preenche_Vet (t_carro *vet, int tam) {
	int i;
	for (i =0; i<tam; i++){
		printf("-----Inserindo carro %d\n", i+1);
		printf("Entre com a marca do carro\n");
		scanf (" %[^\n]s", vet[i].marca);
		printf("Entre com o ano\n");
		scanf (" %d", &vet[i].ano);
		printf("Entre com a cor do carro\n");
		scanf (" %[^\n]s", vet[i].cor);
		printf("Entre com seu preco\n");
		scanf (" %f", 
			&vet[i].preco);
	}
	return;
}

void imprime_Carros_preco (t_carro *vet, int tam, float preco) {
	int i;
	for (i =0; i<tam; i++){
		if (vet[i].preco<= preco){
			printf("*******************\n");
			printf("marca %s\n", vet[i].marca);
			printf("ano %d\n", vet[i].ano);
			printf("cor %s\n", vet[i].cor);
		}
	}
	return;
}

float retorna_Carro_Carac (t_carro *vet, int tam, char *marca, int ano, char *cor) {
	int i;
	for (i =0; i<tam; i++){
		if (strcmp (marca, vet[i].marca)==0 && ano == vet[i].ano && strcmp (cor, vet[i].cor)==0){
			return vet[i].preco;
		}
	}
	return 0;
}


int main(void){
	t_carro vetcarros[TAMVET];
	preenche_Vet (vetcarros, TAMVET);
	imprime_Carros_preco (vetcarros, TAMVET, 10000);
	printf("\n\n\n\n");
	printf("%f\n", retorna_Carro_Carac (vetcarros, TAMVET, "Fiat", 2015, "Azul Marinho"));
	return 0;
}