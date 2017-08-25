#include <stdio.h>

void troca(float *p, float*q ) {
	float aux;
	aux = *p;
	*p=*q;
	*q = aux;
	return;
}

int main(void){
	float x, y, z;
	x = 12;
	y =11;
	z = 10;
	printf("Antes da troca: x= %f, y= %f, z= %f\n", x, y, z);
	//Chamada da função
	if (y < x){
		troca (&x, &y);
	}else {
		if (z < x){
			troca (&x, &z);
		}

	}
	if (z<y){
		troca (&y, &z);
	}

	printf("Depois das trocas: x= %f, y= %f, z = %f\n", x, y, z);
	return 0;
}