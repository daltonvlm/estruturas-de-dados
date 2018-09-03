/*
 * Implemente funções para inserir e retirar um elemento de uma lista circular dupla-
 * mente encadeada.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
	int info;
	No *ant;
	No *prox;
};

struct lista {
	No *prim;
};

static void *aloca(int n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

void insere(Lista * lst, int info)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = info;
	novo->ant = novo->prox = novo;
	if (lst->prim) {
		novo->prox = lst->prim;
		novo->ant = lst->prim->ant;
		novo->ant->prox = novo;
		novo->prox->ant = novo;
	}
	lst->prim = novo;
}

void retira(Lista * lst, int info)
{
	if (lst->prim) {
		No **p = &lst->prim;
		do {
			if ((*p)->info == info) {
				break;
			}
			p = &(*p)->prox;
		} while ((*p) != lst->prim);
		if ((*p)->info == info) {
			No *t = *p;
			if (t == t->prox) {
				*p = NULL;
			} else {
				t->ant->prox = t->prox;
				t->prox->ant = t->ant;
				*p = t->prox;	// Uma possível duplicação ncessária para o caso de *p == lst->prim
			}
			free(t);
		}
	}
}

static void imprime(Lista * lst)
{
	No *p = lst->prim;
	if (p) {
		do {
			printf("%d ", p->info);
			p = p->prox;
		} while (p != lst->prim);
	}
	puts("");
}

static void libera(Lista * lst)
{
	No *p = lst->prim;
	if (p) {
		do {
			No *t = p;
			p = p->prox;
			free(t);
		} while (p != lst->prim);
	}
	free(lst);
}

int main(void)
{
	int n = 10;
	Lista *lst = (Lista *) aloca(sizeof(Lista));
	for (int i = 0; i < n; i++) {
		insere(lst, i);
	}
	imprime(lst);
	for (int i = 0; i < n; i++) {
		retira(lst, i);
		imprime(lst);
	}
	libera(lst);
	return 0;
}
