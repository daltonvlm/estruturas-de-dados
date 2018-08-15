#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

int main(void)
{
	Fila2 *f = fila2_cria();

	for (int i = 1; i < 20; i++) {
		fila2_insere_fim(f, i);
	}
	fila2_insere_ini(f, 0);

	printf("%.2f\n", fila2_retira_fim(f));
	while (!fila2_vazia(f)) {
		printf("%.2f\n", fila2_retira_ini(f));
	}
	fila2_libera(f);

	return 0;
}
