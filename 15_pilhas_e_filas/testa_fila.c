#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void)
{
	Fila *f = fila_cria();

	for (int i = 0; i < 20; i++) {
		fila_insere(f, i);
	}

	fila_imprime(f);

	while (!fila_vazia(f)) {
		fila_retira(f);
	}

	printf("Fila vazia? %d\n", fila_vazia(f));
	fila_libera(f);
	return 0;
}
