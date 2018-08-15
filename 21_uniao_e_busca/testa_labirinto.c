#include <stdio.h>
#include <stdlib.h>
#include "labirinto.h"

int main(void)
{
	Labirinto *m = labirinto_cria(25, 15);

	labirinto_imprime(m);
	labirinto_libera(m);
	return 0;
}
