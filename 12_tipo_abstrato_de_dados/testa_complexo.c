#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

int main(void)
{
	Complexo *a, *b, *c;
	a = cmplx_cria(1.0, 2.0);
	b = cmplx_cria(3.0, 4.0);
	c = cmplx_soma(a, b);
	c = cmplx_subtrai(a, b);
	c = cmplx_multiplica(a, b);
	c = cmplx_divide(a, b);
	cmplx_libera(a);
	cmplx_libera(b);
	cmplx_libera(c);
	return 0;
}
