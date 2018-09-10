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
		perror("");
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

void *lgen_percorre(ListaGen * lst, void *(*cb) (void *info, void *dado),
		    void *dado)
{
	for (ListaGenNo * p = lst->prim; p; p = p->prox) {
		void *r = cb(p->info, dado);
		if (r) {
			return r;
		}
	}
	return NULL;
}

void lgen_libera(ListaGen * lst, void (*cb_libera) (void *))
{
	while (lst->prim) {
		ListaGenNo *t = lst->prim;
		lst->prim = t->prox;
		if (cb_libera) {
			cb_libera(t->info);
		}
		free(t);
	}
	free(lst);
}
