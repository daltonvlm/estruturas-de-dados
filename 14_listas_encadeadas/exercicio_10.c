/*
 * Implemente uma função que transforma uma lista simplesmente encadeada numa
 * lista circular. O protótipo da função deve ser:
 *
 * 		void para_circular (Lista *l);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
	char *info;
	No *prox;
};

struct lista {
	No *prim;
};

void para_circular(Lista * l)
{
	No *p = l->prim;

	while (p && p->prox) {
		p = p->prox;
	}

	if (p) {
		p->prox = l->prim;
	}
}

static void imprime(Lista * lst)
{
	No *p = lst->prim;

	if (p) {
		do {
			puts(p->info);
			p = p->prox;
		} while (p != lst->prim);
	}
	puts("");
}

int main(void)
{
	No no9 = { "nove", NULL };
	No no8 = { "oito", &no9 };
	No no7 = { "sete", &no8 };
	No no6 = { "seis", &no7 };
	No no5 = { "cinco", &no6 };
	No no4 = { "quatro", &no5 };
	No no3 = { "tres", &no4 };
	No no2 = { "dois", &no3 };
	No no1 = { "um", &no2 };
	No no0 = { "zero", &no1 };

	Lista lst = { &no0 };

	para_circular(&lst);
	imprime(&lst);

	return 0;
}
