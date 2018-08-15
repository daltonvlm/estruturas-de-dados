/*
 * Considerando listas encadeadas de valores inteiros, implemente uma função que
 * retorne o número de nós da lista que possuem o campo info com valores maiores
 * do que x. Essa função deve obedecer ao protótipo:
 *
 * 		int maiores (Lista *l, int x);
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

int maiores(Lista * l, int x)
{
	int n = 0;
	No *p = l->prim;
	while (p) {
		if (p->info > x) {
			n++;
		}
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

	printf("%d\n", maiores(&lst, 4));
	return 0;
}
