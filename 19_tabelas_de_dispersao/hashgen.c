#include <stdio.h>
#include <stdlib.h>
#include "hashgen.h"

#define NTAB 101

typedef struct elemento Elemento;
struct elemento {
	void *key;
	void *info;
	Elemento *prox;
};

struct hashgen {
	HashFunc hash;
	Elemento **v;
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

HashGen *hgen_cria(HashFunc hfunc)
{
	HashGen *tab = (HashGen *) aloca(sizeof(HashGen));
	tab->hash = hfunc;
	tab->v = (Elemento **) aloca(NTAB * sizeof(Elemento *));
	for (int i = 0; i < NTAB; i++) {
		tab->v[i] = NULL;
	}
	return tab;
}

void hgen_libera(HashGen * tab, void (*libera) (void *key, void *info))
{
	for (int i = 0; i < NTAB; i++) {
		Elemento *e = tab->v[i];
		while (e) {
			Elemento *t = e;
			e = e->prox;
			if (libera) {
				libera(t->key, t->info);
			}
			free(t);
		}
	}
	free(tab->v);
	free(tab);
}

void hgen_insere(HashGen * tab, void *key, void *info)
{
	int h = tab->hash(key) % NTAB;
	Elemento *e = (Elemento *) aloca(sizeof(Elemento));

	e->key = key;
	e->info = info;
	e->prox = tab->v[h];
	tab->v[h] = e;
}

void *hgen_busca(HashGen * tab, void *key, int (*cmp) (void *, void *))
{
	int h = tab->hash(key) % NTAB;

	for (Elemento * e = tab->v[h]; e; e = e->prox) {
		if (!cmp(key, e->key)) {
			return e->info;
		}
	}
	return NULL;
}

void *hgen_percorre(HashGen * tab,
		    void *(*cb) (void *key, void *info, void *dado), void *dado)
{
	void *r = NULL;
	for (int i = 0; i < NTAB; i++) {
		for (Elemento * e = tab->v[i]; e; e = e->prox) {
			if ((r = cb(e->key, e->info, dado))) {
				break;
			}
		}
	}
	return r;
}
