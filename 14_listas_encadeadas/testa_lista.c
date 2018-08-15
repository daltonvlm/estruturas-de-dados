#include <stdio.h>
#include "lista.h"

int main(void)
{
	Lista *lst = lst_cria();
	lst_insere(lst, 23);
	lst_insere(lst, 45);
	lst_insere(lst, 56);
	lst_insere(lst, 78);
	lst_imprime(lst);
	lst_retira(lst, 78);
	lst_imprime(lst);
	lst_retira(lst, 45);
	lst_imprime(lst);
	lst_libera(lst);
	return 0;
}
