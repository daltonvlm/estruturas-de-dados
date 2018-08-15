#include <stdio.h>
#include <stdlib.h>
#include "vetorpontos.h"
#include "ponto.h"
#include "aresta.h"
#include "heap.h"

typedef struct vetorpontos VetorPontos;

struct vetorpontos {
	int n, d;
	Ponto **v;
};

static void verifica(void *p)
{
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	verifica(p);
	return p;
}

VetorPontos *vetorpontos_cria(void)
{
	VetorPontos *vp = (VetorPontos *) aloca(sizeof(VetorPontos));
	vp->n = 0;
	vp->d = 8;
	vp->v = (Ponto **) aloca(vp->d * sizeof(Ponto *));
	return vp;
}

void vetorpontos_insere(VetorPontos * vp, Ponto * p)
{
	if (vp->n == vp->d) {
		vp->d *= 2;
		vp->v = (Ponto **) realloc(vp->v, vp->d * sizeof(Ponto *));
		verifica(vp->v);
	}
	vp->v[vp->n++] = p;
}

void vetorpontos_libera(VetorPontos * vp, void (*libera) (void *))
{
	if (libera) {
		for (int i = 0; i < vp->n; i++) {
			libera(vp->v[i]);
		}
	}
	free(vp);
}

static int cmp_arestas(const void *p, const void *q)
{
	Aresta *a = (Aresta *) p;
	Aresta *b = (Aresta *) q;
	return aresta_pega_distancia(a) >= aresta_pega_distancia(b) ? -1 : 1;
}

Heap *vetorpontos_cria_arestas(VetorPontos * vp)
{
	Heap*h=heap_cria(cmp_arestas);
	for(int i=0;i<vp->n;i++){
		for(int j=i+1;j<vp->n;j++){
			Aresta*a=aresta_cria(vp->v[i],vp->v[j]);
			heap_insere(h,a);
		}
	}
	return h;
}
