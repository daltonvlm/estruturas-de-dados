#include "vetordin.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct vetordin {
	int n;
	int nmax;
	float *v;
};

VetorDin *vd_cria(void)
{
	VetorDin *vd = (VetorDin *) malloc(sizeof(VetorDin));
	if (!vd) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	vd->n = 0;
	vd->nmax = 4;
	vd->v = (float *)malloc(vd->nmax * sizeof(float));
	if (!vd->v) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return vd;
}

static void realoca(VetorDin * vd)
{
	float *tmp;

	vd->nmax *= 2;
	tmp = (float *)realloc(vd->v, vd->nmax * sizeof(float));

	if (!tmp) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}

	vd->v = tmp;
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
