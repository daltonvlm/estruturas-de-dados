#include <stdio.h>
#include <stdlib.h>
#include "arvn_char.h"

int main(void)
{
	Arvn *x;

	ArvnNo *a = arvn_criano('a');
	ArvnNo *b = arvn_criano('b');
	ArvnNo *c = arvn_criano('c');
	ArvnNo *d = arvn_criano('d');
	ArvnNo *e = arvn_criano('e');
	ArvnNo *f = arvn_criano('f');
	ArvnNo *g = arvn_criano('g');
	ArvnNo *h = arvn_criano('h');
	ArvnNo *i = arvn_criano('i');
	ArvnNo *j = arvn_criano('j');
	arvn_insere(a, g);
	arvn_insere(a, f);
	arvn_insere(a, b);
	arvn_insere(b, e);
	arvn_insere(b, c);
	arvn_insere(c, d);
	arvn_insere(g, i);
	arvn_insere(g, h);
	arvn_insere(i, j);

	x = arvn_cria(a);
	arvn_imprime(x);
	printf("Altura: %d\n", arvn_altura(x));
	arvn_libera(x);
	return 0;
}
