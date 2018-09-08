#include <stdio.h>
#include <stdlib.h>
#include "abb_int.h"

int main(void)
{
	Arv *a = abb_cria();

	puts("\nInserindo elementos");
	while (1) {
		int v;
		printf("\nValor: ");
		if (1 == scanf("%d", &v)) {
			abb_insere(a, v);
			abb_imprime(a);
		} else {
			break;
		}
	}

	puts("\nRetirando elementos");
	while (!abb_vazia(a)) {
		int v;
		printf("\nValor: ");
		if (1 == scanf("%d", &v)) {
			abb_retira(a, v);
			abb_imprime(a);
		} else {
			break;
		}
	}

	puts("Liberando arvore");
	abb_imprime(a);
	abb_libera(a);
	return 0;
}
