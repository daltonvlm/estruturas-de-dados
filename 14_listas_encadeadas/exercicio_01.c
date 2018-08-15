/*
 * Implemente um função que tenha como valor de retorno o comprimento de uma
 * lista encadeada, isto é, que calcule o número de nós de uma lista. Essa função deve
 * obedecer ao protótipo:
 *
 * 		int comprimento (Lista* l);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
	int info;
	No *prox;
};

struct lista {
	No *prim;
};

int comprimento(Lista * l)
{
	int n = 0;
	No *p = l->prim;
	while (p) {
		n++;
		p = p->prox;
	}
	return n;
}

int main(void)
{
	No no9 = { 9, NULL };
	No no8 = { 8, &no9 };
	No no7 = { 7, &no8 };
	No no6 = { 6, &no7 };
	No no5 = { 5, &no6 };
	No no4 = { 4, &no5 };
	No no3 = { 3, &no4 };
	No no2 = { 2, &no3 };
	No no1 = { 1, &no2 };
	No no0 = { 0, &no1 };
	Lista lst = { &no0 };

	printf("comprimento = %d\n", comprimento(&lst));
	return 0;
}
