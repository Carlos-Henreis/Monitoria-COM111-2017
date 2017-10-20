int main (void) {
	listaDE *f;
	f = create();
	insert(f,12);
	insert(f,320);
	insert(f,413);
	insert(f,197);
	insert(f,197);
	insert(f,26);
	imprime(f);
	remover(f,320);
	imprime(f);
	return 0;
}