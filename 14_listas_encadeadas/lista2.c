#include "lista2.h"

#include <stdio.h>
#include <stdlib.h>

struct lista2 {
	No *prim;
	No *ult;
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

Lista2 *lst2_cria(void)
{
	Lista2 *lst = (Lista2 *) aloca(sizeof(Lista2));
	lst->prim = NULL;
	lst->ult = NULL;
	return lst;
}

void lst2_libera(Lista2 * lst)
{
	while (lst->prim) {
		No *t = lst->prim;
		lst->prim = t->prox;
		free(t);
	}
	free(lst);
}

void lst2_insere_inicio(Lista2 * lst, int v)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = v;
	novo->ant = NULL;
	novo->prox = lst->prim;

	if (lst->prim) {
		lst->prim->ant = novo;
	} else {
		lst->ult = novo;
	}
	lst->prim = novo;
}

void lst2_insere_final(Lista2 * lst, int v)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = v;
	novo->ant = lst->ult;
	novo->prox = NULL;

	if (lst->ult) {
		lst->ult->prox = novo;
	} else {
		lst->prim = novo;
	}
	lst->ult = novo;
}

No *lst2_busca(Lista2 * lst, int v)
{
	No *p = lst->prim;
	while (p && p->info != v) {
		p = p->prox;
	}
	return p;
}

void lst2_retira(Lista2 * lst, int v)
{
	No **p = &lst->prim;

	while (*p && (*p)->info != v) {
		p = &(*p)->prox;
	}

	if (*p) {
		No *t = *p;
		if ((*p)->prox) {
			(*p)->prox->ant = (*p)->ant;
		} else {
			lst->ult = (*p)->ant;
		}
		*p = (*p)->prox;
		free(t);
	}
}

int lst2_vazia(Lista2 * lst)
{
	return !lst->prim;
}
