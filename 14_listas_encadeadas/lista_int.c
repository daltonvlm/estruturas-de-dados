#include <stdio.h>
#include <stdlib.h>
#include "lista_int.h"

typedef struct listano ListaNo;
struct listano {
	int info;
	ListaNo *prox;
};

struct lista {
	ListaNo *prim;
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

Lista *lst_cria(void)
{
	Lista *lst = (Lista *) aloca(sizeof(Lista));
	lst->prim = NULL;
	return lst;
}

void lst_libera(Lista * lst)
{
	while (lst->prim) {
		ListaNo *t = lst->prim;
		lst->prim = t->prox;
		free(t);
	}
	free(lst);
}

static void libera_nos(ListaNo * p)
{
	if (p) {
		libera_nos(p->prox);
		free(p);
	}
}

void lst_libera_rec(Lista * lst)
{
	libera_nos(lst->prim);
	free(lst);
}

void lst_insere(Lista * lst, int info)
{
	ListaNo *novo = (ListaNo *) aloca(sizeof(ListaNo));
	novo->info = info;
	novo->prox = lst->prim;
	lst->prim = novo;
}

void lst_insere_ordenado(Lista * lst, int info)
{
	ListaNo **p = &lst->prim;
	ListaNo *novo = (ListaNo *) aloca(sizeof(ListaNo));

	novo->info = info;
	while (*p && (*p)->info < info) {
		p = &(*p)->prox;
	}
	novo->prox = *p;
	*p = novo;
}

void lst_retira(Lista * lst, int info)
{
	ListaNo **p = &lst->prim;
	while (*p && (*p)->info != info) {
		p = &(*p)->prox;
	}
	if (*p) {
		ListaNo *t = *p;
		*p = t->prox;
		free(t);
	}
}

/*
static ListaNo *retira_nos(ListaNo * p, int info)
{
	if (p) {
		if (p->info == info) {
			ListaNo *t = p;
			p = p->prox;
			free(t);
		} else {
			p->prox = retira_nos(p->prox, info);
		}
	}
	return p;
}

void lst_retira_rec(Lista * lst, int info)
{
	lst->prim = retira_nos(lst->prim, info);
}
*/

static void retira_nos(ListaNo ** p, int info)
{
	if (*p) {
		if ((*p)->info == info) {
			ListaNo *t = *p;
			*p = t->prox;
			free(t);
		} else {
			retira_nos(&(*p)->prox, info);
		}
	}
}

void lst_retira_rec(Lista * lst, int info)
{
	retira_nos(&lst->prim, info);
}

int lst_vazia(Lista * lst)
{
	return !lst->prim;
}

int lst_pertence(Lista * lst, int info)
{
	for (ListaNo * p = lst->prim; p; p = p->prox) {
		if (info == p->info) {
			return 1;
		}
	}
	return 0;
}

void lst_imprime(Lista * lst)
{
	for (ListaNo * p = lst->prim; p; p = p->prox) {
		printf("%d -> ", p->info);
	}
	puts("NULL");
}

static void imprime_nos(ListaNo * p)
{
	if (p) {
		printf("%d -> ", p->info);
		imprime_nos(p->prox);
	} else {
		puts("NULL");
	}
}

void lst_imprime_rec(Lista * lst)
{
	imprime_nos(lst->prim);
}

static void imprime_nos_rev(ListaNo * p)
{
	if (p) {
		imprime_nos_rev(p->prox);
		printf(" -> %d", p->info);
	} else {
		printf("NULL");
	}
}

void lst_imprime_rev(Lista * lst)
{
	imprime_nos_rev(lst->prim);
	puts("");
}

int lst_igual(Lista * lst1, Lista * lst2)
{
	ListaNo *p1, *p2;
	for (p1 = lst1->prim, p2 = lst2->prim;
	     p1 && p2; p1 = p1->prox, p2 = p2->prox) {
		if (p1->info != p2->info) {
			return 0;
		}
	}
	return p1 == p2;
}

static int nos_iguais(ListaNo * p1, ListaNo * p2)
{
	if (p1 && p2) {
		return p1->info == p2->info && nos_iguais(p1->prox, p2->prox);
	}
	return p1 == p2;
}

int lst_igual_rec(Lista * lst1, Lista * lst2)
{
	return nos_iguais(lst1->prim, lst2->prim);
}
