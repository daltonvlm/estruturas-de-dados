#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
	int info;
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

Lista *lst_cria(void)
{
	Lista *lst = (Lista *) aloca(sizeof(Lista));
	lst->prim = NULL;
	return lst;
}

void lst_libera(Lista * lst)
{
	while (lst->prim) {
		No *tmp = lst->prim;
		lst->prim = lst->prim->prox;
		free(tmp);
	}
	free(lst);
}

static void libera_nos(No * p)
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

void lst_insere(Lista * lst, int v)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = v;
	novo->prox = lst->prim;
	lst->prim = novo;
}

void lst_insere_ordenado(Lista * lst, int v)
{
	No **pno = &lst->prim;
	No *novo = (No *) aloca(sizeof(No));

	novo->info = v;

	while (*pno && (*pno)->info < v) {
		pno = &(*pno)->prox;
	}
	novo->prox = *pno;
	*pno = novo;
}

void lst_retira(Lista * lst, int v)
{
	No **pno = &lst->prim;

	while (*pno && (*pno)->info != v) {
		pno = &(*pno)->prox;
	}
	if (*pno) {
		No *tmp = *pno;
		*pno = (*pno)->prox;
		free(tmp);
	}
}

/*
static No* retira_nos(No*p,int v){
	if(p){
		if(p->info==v){
			No*t=p;
			p=p->prox;
			free(t);
		}else{
			p->prox=retira_nos(p->prox,v);
		}
	}
	return p;
}

void lst_retira_rec(Lista*lst,int v){
	lst->prim=retira_nos(lst->prim,v);
}
*/

static void retira_nos(No ** p, int v)
{
	if (*p) {
		if ((*p)->info == v) {
			No *t = *p;
			*p = (*p)->prox;
			free(t);
		} else {
			retira_nos(&(*p)->prox, v);
		}
	}
}

void lst_retira_rec(Lista * lst, int v)
{
	retira_nos(&lst->prim, v);
}

int lst_vazia(Lista * lst)
{
	return !lst->prim;
}

int lst_pertence(Lista * lst, int v)
{
	for (No * no = lst->prim; no; no = no->prox) {
		if (no->info == v) {
			return 1;
		}
	}
	return 0;
}

void lst_imprime(Lista * lst)
{
	for (No * no = lst->prim; no; no = no->prox) {
		printf("%d ", no->info);
	}
	puts("");
}

static void imprime_nos(No * p)
{
	if (p) {
		printf("%d ", p->info);
		imprime_nos(p->prox);
	}
}

void lst_imprime_rec(Lista * lst)
{
	imprime_nos(lst->prim);
	puts("");
}

static void imprime_nos_rev(No * p)
{
	if (p) {
		imprime_nos_rev(p->prox);
		printf("%d ", p->info);
	}
}

void lst_imprime_rev(Lista * lst)
{
	imprime_nos_rev(lst->prim);
	puts("");
}

int lst_igual(Lista * lst1, Lista * lst2)
{
	No *p1 = lst1->prim;
	No *p2 = lst2->prim;

	while (p1 && p2) {
		if (p1->info != p2->info) {
			return 0;
		}
		p1 = p1->prox;
		p2 = p2->prox;
	}
	return p1 == p2;
}

static int nos_iguais(No * p1, No * p2)
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
