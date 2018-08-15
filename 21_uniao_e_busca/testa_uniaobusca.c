#include <stdio.h>
#include <stdlib.h>
#include "uniaobusca.h"

int main(void)
{
	int n = 6;
	UniaoBusca *ub = ub_cria(n);

	ub_uniao(ub, 0, 2);
	ub_uniao(ub, 0, 3);
	ub_uniao(ub, 2, 5);
	ub_uniao(ub, 1, 4);

	ub_uniao(ub, 0, 1);

	for (int i = 0; i < n; i++) {
		printf("%d -> %d\n", i, ub_busca(ub, i));
	}

	ub_libera(ub);
	return 0;
}
