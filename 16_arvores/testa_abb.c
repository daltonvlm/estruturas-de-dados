#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main(void)
{
	Arv *a = abb_cria();

	for (int i = 10; i >= 0; i--) {
		abb_insere(a, i);
	}

	abb_imprime(a);
	abb_libera(a);

	return 0;
}
