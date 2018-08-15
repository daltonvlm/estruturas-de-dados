#include <stdio.h>
#include <stdlib.h>
#include "listagen.h"

typedef struct listagenno ListaGenNo;

struct listagenno {
	void *info;
	ListaGenNo *prox;
};
struct listagen {
	ListaGenNo *prim;
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

ListaGen *lgen_cria(void)
{
	ListaGen *lst = (ListaGen *) aloca(sizeof(ListaGen));
	lst->prim = NULL;
	return lst;
}

void lgen_insere(ListaGen * lst, void *p)
{
	ListaGenNo *novo = (ListaGenNo *) aloca(sizeof(ListaGenNo));
	novo->info = p;
	novo->prox = lst->prim;
	lst->prim = novo;
}

void *lgen_percorre(ListaGen * lst, void *(*cb) (void *, void *), void *dado)
{
	void *r = NULL;
	for (ListaGenNo * p = lst->prim; p; p = p->prox) {
		if (r = cb(p->info, dado)) {
			break;
		}
	}
	return r;
}

void lgen_libera(ListaGen * lst, void (*cb) (void *))
{
	ListaGenNo *p = lst->prim;
	while (p) {
		ListaGenNo *t = p;
		p = p->prox;
		cb(t->info);
		free(t);
	}
	free(lst);
}
