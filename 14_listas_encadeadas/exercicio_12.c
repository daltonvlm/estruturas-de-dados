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
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

void insere(Lista * lst, int v)
{
	No *novo = (No *) aloca(sizeof(No));

	novo->info = v;
	novo->ant = novo->prox = novo;

	if (lst->prim) {
		novo->prox = lst->prim;
		novo->ant = lst->prim->ant;

		novo->prox->ant = novo;
		novo->ant->prox = novo;
	}
	lst->prim = novo;
}

void retira(Lista * lst, int v)
{
	No **p = &lst->prim;

	if (*p) {
		do {
			if ((*p)->info == v) {
				break;
			}
			p = &(*p)->prox;
		} while (*p != lst->prim);

		if ((*p)->info == v) {
			No *t = *p;

			if (t->prox == t) {
				*p = NULL;
			} else {
				t->prox->ant = t->ant;
				t->ant->prox = t->prox;
				*p = t->prox;
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
	Lista *lst = (Lista *) aloca(sizeof(Lista));

	for (int i = 0; i < 10; i++) {
		insere(lst, i);
	}

	imprime(lst);

	for (int i = 0; i < 10; i++) {
		retira(lst, i);
		imprime(lst);
	}

	libera(lst);
	return 0;
}
