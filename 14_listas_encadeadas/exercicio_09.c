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

static void *aloca(int n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

Lista *copia(Lista * l)
{
	No *atual = l->prim;
	No **p;
	Lista *cp = (Lista *) aloca(sizeof(Lista));

	p = &cp->prim;

	while (atual) {
		*p = (No *) aloca(sizeof(No));
		strcpy((*p)->info, atual->info);
		atual = atual->prox;
		p = &(*p)->prox;
	}
	*p = NULL;
	return cp;
}

static No *copia_no(No * no)
{
	if (!no) {
		return NULL;
	}
	No *cp = (No *) aloca(sizeof(No));
	strcpy(cp->info, no->info);
	cp->prox = copia_no(no->prox);
	return cp;
}

Lista *copia_rec(Lista * l)
{
	Lista *cp = (Lista *) aloca(sizeof(Lista));
	cp->prim = copia_no(l->prim);
	return cp;
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
	No *p = lst->prim;
	while (p) {
		puts(p->info);
		p = p->prox;
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
	Lista *cp = copia_rec(&lst);

	puts("Lista:");
	imprime(&lst);

	puts("Copia:");
	imprime(cp);
	libera(cp);

	return 0;
}
