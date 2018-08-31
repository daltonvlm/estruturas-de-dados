#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vetordin.h"

struct vetordin {
	int n;
	int nmax;
	float *v;
};

static void check(void *p)
{
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

VetorDin *vd_cria(void)
{
	VetorDin *vd = (VetorDin *) aloca(sizeof(VetorDin));
	vd->n = 0;
	vd->nmax = 4;
	vd->v = (float *)aloca(vd->nmax * sizeof(float));
	return vd;
}

static void realoca(VetorDin * vd)
{
	vd->nmax *= 2;
	vd->v = (float *)realloc(vd->v, vd->nmax * sizeof(float));
	if (!vd->v) {
		perror("");
		exit(EXIT_FAILURE);
	}
}

void vd_insere(VetorDin * vd, float x)
{
	if (vd->n == vd->nmax) {
		realoca(vd);
	}
	vd->v[vd->n++] = x;
}

int vd_tam(VetorDin * vd)
{
	return vd->n;
}

float vd_acessa(VetorDin * vd, int i)
{
	assert(i >= 0 && i < vd->n);
	return vd->v[i];
}

void vd_libera(VetorDin * vd)
{
	free(vd->v);
	free(vd);
}
