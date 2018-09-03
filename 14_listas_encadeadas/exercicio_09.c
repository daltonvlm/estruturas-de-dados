/*
 * Considerando listas que armazenam cadeias de caracteres, implemente as versões
 * iterativa e recursiva de uma função que cria uma cópia de uma lista encadeada.
 * Essa função deve obedecer ao protótipo:
 *
 * 		Lista* copia (Lista* l);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 121

typedef struct no No;
typedef struct lista Lista;

struct no {
	char info[MAX];
	No *prox;
};

struct lista {
	No *prim;
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

static No *copia_no(No * p)
{
	No *cpy = (No *) aloca(sizeof(No));
	strcpy(cpy->info, p->info);
	cpy->prox = NULL;
	return cpy;
}

Lista *copia(Lista * l)
{
	Lista *cpy = (Lista *) aloca(sizeof(Lista));
	No **p = &cpy->prim;
	for (No * q = l->prim; q; q = q->prox) {
		*p = copia_no(q);
		p = &(*p)->prox;
	}
	return cpy;
}

static void copia_nos(No ** cpy, No * orig)
{
	if (orig) {
		*cpy = copia_no(orig);
		copia_nos(&(*cpy)->prox, orig->prox);
	}
}

Lista *copia_rec(Lista * l)
{
	Lista *cpy = (Lista *) aloca(sizeof(Lista));
	copia_nos(&cpy->prim, l->prim);
	return cpy;
}

void libera(Lista * lst)
{
	while (lst->prim) {
		No *t = lst->prim;
		lst->prim = t->prox;
		free(t);
	}
	free(lst);
}

void imprime(Lista * lst)
{
	for (No * p = lst->prim; p; p = p->prox) {
		puts(p->info);
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
	//Lista *cp = copia(&lst);
	Lista *cp = copia_rec(&lst);

	puts("Lista:");
	imprime(&lst);

	puts("Copia:");
	imprime(cp);
	libera(cp);

	return 0;
}
