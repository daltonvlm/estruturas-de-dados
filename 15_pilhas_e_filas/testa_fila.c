#include <stdio.h>
#include <stdlib.h>
#include "fila_float.h"

int main(void)
{
	Fila *f = fila_cria();
	fila_insere(f, 20.0);
	fila_insere(f, 20.8);
	fila_insere(f, 21.2);
	fila_insere(f, 24.3);
	printf("Primeiro elemento: %f\n", fila_retira(f));
	printf("Segundo elemento: %f\n", fila_retira(f));
	printf("Configuracao da fila:\n");
	fila_imprime(f);
	fila_libera(f);
	return 0;
}
