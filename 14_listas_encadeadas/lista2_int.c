#include <stdio.h>
#include <stdlib.h>
#include "lista2_int.h"

typedef struct listano2 ListaNo2;
struct listano2 {
	int info;
	ListaNo2 *ant;
	ListaNo2 *prox;
};

struct lista2 {
	ListaNo2 *prim;
	ListaNo2 *ult;
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
		ListaNo2 *t = lst->prim;
		lst->prim = t->prox;
		free(t);
	}
	free(lst);
}

void lst2_insere_inicio(Lista2 * lst, int info)
{
	ListaNo2 *novo = (ListaNo2 *) aloca(sizeof(ListaNo2));
	novo->info = info;
	novo->ant = NULL;
	novo->prox = lst->prim;
	if (lst->prim) {
		lst->prim->ant = novo;
	} else {
		lst->ult = novo;
	}
	lst->prim = novo;
}

void lst2_insere_final(Lista2 * lst, int info)
{
	ListaNo2 *novo = (ListaNo2 *) aloca(sizeof(ListaNo2));
	novo->info = info;
	novo->ant = lst->ult;
	novo->prox = NULL;
	if (lst->ult) {
		lst->ult->prox = novo;
	} else {
		lst->prim = novo;
	}
	lst->ult = novo;
}

void lst2_retira(Lista2 * lst, int info)
{
	ListaNo2 **p = &lst->prim;
	while (*p && (*p)->info != info) {
		p = &(*p)->prox;
	}
	if (*p) {
		ListaNo2 *t = *p;
		if (t->prox) {
			t->prox->ant = t->ant;
		} else {
			lst->ult = t->ant;
		}
		*p = t->prox;
		free(t);
	}
}

int lst2_vazia(Lista2 * lst)
{
	return !lst->prim;
}
