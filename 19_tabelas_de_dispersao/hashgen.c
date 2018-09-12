#include <stdio.h>
#include <stdlib.h>
#include "hashgen.h"

#define NTAB 101

typedef struct elemento Elemento;

struct elemento {
	void *chave;
	void *info;
	Elemento *prox;
};

struct hashgen {
	HashFunc hash;
	Elemento *vet[NTAB];
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

HashGen *hgen_cria(HashFunc hfunc)
{
	HashGen *tab = (HashGen *) aloca(sizeof(HashGen));
	tab->hash = hfunc;
	for (int i = 0; i < NTAB; i++) {
		tab->vet[i] = NULL;
	}
	return tab;
}

void hgen_libera(HashGen * tab, void (*cb_libera) (void *info))
{
	for (int i = 0; i < NTAB; i++) {
		while (tab->vet[i]) {
			Elemento *t = tab->vet[i];
			tab->vet[i] = t->prox;
			if (cb_libera) {
				cb_libera(t->info);
			}
			free(t);
		}
	}
	free(tab);
}

static int calcula_hash(int h)
{
	return h % NTAB;
}

void hgen_insere(HashGen * tab, void *chave, void *info,
		 int (*cb_cmp) (void *chave, void *chave2))
{
	int h = calcula_hash(tab->hash(chave));
	Elemento *e;
	for (e = tab->vet[h]; e; e = e->prox) {
		if (!cb_cmp(chave, e->chave)) {
			break;
		}
	}
	if (!e) {
		e = (Elemento *) aloca(sizeof(Elemento));
		e->chave = chave;
		e->prox = tab->vet[h];
		tab->vet[h] = e;
	}
	/*
	 * Aqui, poderá ocorrer o caso em que já exista informação armazenada com a chave passada.
	 * Nesse caso, terá cabido ao cliente liberar a memória ocupada pela antiga informação.
	 */
	e->info = info;
}

void *hgen_busca(HashGen * tab, void *chave,
		 int (*cb_cmp) (void *chave1, void *chave2))
{
	int h = calcula_hash(tab->hash(chave));
	for (Elemento * e = tab->vet[h]; e; e = e->prox) {
		if (!cb_cmp(chave, e->chave)) {
			return e->info;
		}
	}
	return NULL;
}

void *hgen_percorre(HashGen * tab, void *(*cb) (void *info, void *dado),
		    void *dado)
{
	void *p = NULL;
	for (int i = 0; i < NTAB; i++) {
		for (Elemento * e = tab->vet[i]; e; e = e->prox) {
			if (p = cb(e->info, dado)) {
				break;
			}
		}
	}
	return p;
}
