#include <stdio.h>
#include <stdlib.h>
#include "fila2_float.h"

int main(void)
{
	Fila2 *f = fila2_cria();

	fila2_insere_fim(f, 20.0);
	fila2_insere_ini(f, 20.8);
	fila2_insere_ini(f, 21.2);
	fila2_insere_ini(f, 24.3);

	printf("Primeiro elemento: %f\n", fila2_retira_ini(f));
	printf("Ultimo elemento: %f\n", fila2_retira_fim(f));
	printf("Configuracao da fila:\n");
	fila2_imprime(f);

	fila2_libera(f);
	return 0;
}
