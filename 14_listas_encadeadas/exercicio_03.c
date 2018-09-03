/*
 * Implemente uma função que retorne o último valor de uma lista encadeada de
 * inteiros. Essa função deve obedecer ao protótipo:
 *
 * 		int ultimo (Lista *l);
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

int ultimo(Lista * l)
{
	No *p = l->prim;
	if (p) {
		while (p->prox) {
			p = p->prox;
		}
		return p->info;
	}
	fprintf(stderr, "Erro: lista vazia\n");
	exit(EXIT_FAILURE);
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
	printf("ultimo = %d\n", ultimo(&lst));
	return 0;
}
