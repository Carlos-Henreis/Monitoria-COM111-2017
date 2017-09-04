#include <stdio.h>
#include <string.h>
#define V 1
#define F 0
#define TAMTITULO 15
#define TAMAUTOR 20
#define TAMESTILO 10

typedef struct livro{
	char titulo[TAMTITULO];
	char autor[TAMAUTOR];
	char estilo[TAMESTILO];
	int codigo;
	float preco;
}tlivro;

void incluir_liv (tlivro *vet, int *numlivros) {
	int i = *numlivros;
	printf("-----Inserindo livro %d\n", i+1);
	printf("Entre com o titulo do livro\n");
	scanf (" %[^\n]s", vet[i].titulo);
	printf("Entre com o autor do livro\n");
	scanf (" %[^\n]s", vet[i].autor);
	printf("Entre com o estilo do livro\n");
	scanf (" %[^\n]s", vet[i].estilo);
	printf("Entre com o codigo\n");
	scanf (" %d", &vet[i].codigo);
	printf("Entre com seu preco\n");
	scanf (" %f", &vet[i].preco);
	*numlivros+=1;
	return;
}

void lista_liv (tlivro *vet, int *numlivros) {
	int i;
	for (i =0; i<*numlivros; i++){
		printf("----------\n");
		printf("titulo do livro %s\n", vet[i].titulo);
		printf("autor do livro %s\n", vet[i].autor);
		printf("estilo do livro %s\n", vet[i].estilo);
		printf("codigo do livro %d\n", vet[i].codigo);
		printf("preco do livro %f\n", vet[i].preco);
	}
	return;

}

void proc_autor (tlivro *vet, int *numlivros){
	char autor[TAMAUTOR];
	int i;
	printf("Entre com o nome do autor\n");
	scanf (" %[^\n]s", autor);
	for (i =0; i<*numlivros; i++){
		if (strcmp(vet[i].autor, autor) == 0){
			printf("autor encontrado, possui livros cadastrados\n");
			return;
		}
	}
	printf("autor não encontrado\n");
	return;
}

void proc_titulo(tlivro *vet, int *numlivros){
	char titulo[TAMAUTOR];
	int i;
	printf("Entre com o titlo\n");
	scanf (" %[^\n]s", titulo);
	for (i =0; i<*numlivros; i++){
		if (strcmp(vet[i].titulo, titulo) == 0){
			printf("Dados do livro\n");
			printf("titulo do livro %s\n", vet[i].titulo);
			printf("autor do livro %s\n", vet[i].autor);
			printf("estilo do livro %s\n", vet[i].estilo);
			printf("codigo do livro %d\n", vet[i].codigo);
			printf("preco do livro %f\n", vet[i].preco);
			return;
		}
	}
	printf("livro não encontrado com este titulo\n");
	return;
}

void proc_estilo (tlivro *vet, int *numlivros){
	char estilo[TAMAUTOR];
	int i, cont =0;

	printf("Entre com o estilo\n");
	scanf (" %[^\n]s", estilo);
	for (i =0; i<*numlivros; i++){
		if (strcmp(vet[i].estilo, estilo) == 0){
			cont +=1;
		}
	}
	if (cont > 0){
		printf("O estilo %s possui %d livros cadastrados\n", estilo, cont);
	}else{
		printf("não existe livros cadastrados com este estilo\n");
	}
	return;
}

void media_preco (tlivro *vet, int *numlivros) {
	int i;
	float media=0;
	for (i =0; i<*numlivros; i++){
		media+= vet[i].preco;
	}
	media/=*numlivros;
	printf ("A média de preco dos livros é: %f", media);
}

void menu( ) {
	printf(" Digite I para incluir um livro. \n");
	printf(" Digite L para listar o nome de todos os livros. \n");
	printf(" Digite A para procurar e exibir os dados do livro por autor. \n");
	printf(" Digite T para procurar e exibir os dados do livro por título. \n");
	printf(" Digite E para procurar e exibir os dados do livro por estilo. \n");
	printf(" Digite M para calcular a média de preço de todos os livros. \n");
	printf( " Digite S para sair \n");
}
// definição da função principal
int main(void) {
	tlivro vetlivro[50];
	char ch;
	int numlivros = 0; //numero de livros cadastrados
	
	do{
		menu ();
		scanf (" %c", &ch);
		switch(ch) {
			case 'I': 
				incluir_liv(vetlivro, &numlivros); 
				break;
			case 'L': 
				lista_liv(vetlivro, &numlivros); 
				break;
			case 'A': 
				proc_autor(vetlivro, &numlivros); 
				break;
			case 'T': 
				proc_titulo(vetlivro, &numlivros); 
				break;
			case 'E': 
				proc_estilo(vetlivro, &numlivros); 
				break;
			case 'M': 
				media_preco(vetlivro, &numlivros); 
				break;
			case 'S':
				break;
			default:
				printf("Erro entre com o campo correto\n");

		} // fim do switch
	}while (ch != 'S');
	return 0;
} // fim da função main.