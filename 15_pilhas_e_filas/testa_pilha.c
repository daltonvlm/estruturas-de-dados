#include <stdio.h>
#include <stdlib.h>
#include "pilha_float.h"

int main(void)
{
	int n = 10;
	Pilha *p = pilha_cria();
	for (int i = 0; i < n; i++) {
		pilha_push(p, i);
	}
	pilha_imprime(p);
	while (!pilha_vazia(p)) {
		pilha_pop(p);
	}
	pilha_libera(p);
	return 0;
}
