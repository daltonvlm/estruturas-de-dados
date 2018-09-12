#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_int.h"

typedef struct elemento Elemento;
struct elemento {
	int info;
	Elemento *prox;
};

struct hash {
	int dim;
	HashFunc hfunc;
	Elemento **tab;
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

Hash *hsh_cria(int dim, HashFunc hfunc)
{
	Hash *hsh = (Hash *) aloca(sizeof(Hash));
	hsh->dim = dim;
	hsh->hfunc = hfunc;
	hsh->tab = (Elemento **) aloca(hsh->dim * sizeof(Elemento *));
	memset(hsh->tab, 0, hsh->dim * sizeof(Elemento *));
	return hsh;
}

void hsh_libera(Hash * hsh)
{
	for (int i = 0; i < hsh->dim; i++) {
		while (hsh->tab[i]) {
			Elemento *t = hsh->tab[i];
			hsh->tab[i] = t->prox;
			free(t);
		}
	}
	free(hsh->tab);
	free(hsh);
}

void hsh_insere(Hash * hsh, int v)
{
	int h = hsh->hfunc(v) % hsh->dim;
	Elemento *e;
	for (e = hsh->tab[h]; e; e = e->prox) {
		if (e->info == v) {
			break;
		}
	}
	if (!e) {
		e = (Elemento *) aloca(sizeof(Elemento));
		e->prox = hsh->tab[h];
		hsh->tab[h] = e;
	}
	e->info = v;
}

int hsh_busca(Hash * hsh, int v)
{
	int h = hsh->hfunc(v) % hsh->dim;
	for (Elemento * e = hsh->tab[h]; e; e = e->prox) {
		if (e->info == v) {
			return 1;
		}
	}
	return 0;
}
