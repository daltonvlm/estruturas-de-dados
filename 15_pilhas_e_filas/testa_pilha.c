#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void)
{
	Pilha *p = pilha_cria();

	for (int i = 0; i < 10; i++) {
		pilha_push(p, i);
	}

	pilha_imprime(p);

	while (pilha_vazia(p)) {
		pilha_pop(p);
	}
	pilha_libera(p);
	return 0;
}
