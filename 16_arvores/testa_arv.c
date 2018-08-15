#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(void)
{
	Arv *a = arv_cria(arv_criano('a',
				     arv_criano('b',
						NULL,
						arv_criano('d', NULL, NULL)),
				     arv_criano('c',
						arv_criano('e', NULL, NULL),
						arv_criano('f', NULL, NULL))
			  )
	    );
	arv_imprime(a);

	puts("");
	if (arv_pertence(a, 'b')) {
		ArvNo *no = arv_busca(a, 'b');
		if (no) {
			puts("encontrado");
		}
	}

	arv_libera(a);
	return 0;
}
