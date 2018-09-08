#include <stdio.h>
#include <stdlib.h>
#include "arv_char.h"

int main(void)
{
	Arv *a = arv_cria(arv_criano('a',
				     arv_criano('b',
						NULL,
						arv_criano('d', NULL, NULL)),
				     arv_criano('c',
						arv_criano('e', NULL, NULL),
						arv_criano('f', NULL, NULL))));
	arv_imprime(a);
	printf("Altura da arvore: %d\n", arv_altura(a));
	arv_libera(a);
	return 0;
}
