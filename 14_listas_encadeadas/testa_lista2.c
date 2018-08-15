#include <stdio.h>
#include "lista2.h"

int main(void)
{
	Lista2 *lst = lst2_cria();

	for (int i = 0; i < 10; i++) {
		lst2_insere_inicio(lst, i);
	}

	for (int i = 10; i >= 0; i--) {
		lst2_retira(lst, i);
	}

	lst2_libera(lst);

	return 0;
}
