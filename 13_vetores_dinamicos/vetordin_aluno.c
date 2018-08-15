#include "vetordin_aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct vetordin {
	int n;
	int nmax;
	Aluno **v;
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
	vd->v = (Aluno **) malloc(vd->nmax * sizeof(Aluno *));
	if (!vd->v) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return vd;
}

static void realoca(VetorDin * vd)
{
	Aluno **tmp;

	vd->nmax *= 2;
	tmp = (Aluno * *)realloc(vd->v, vd->nmax * sizeof(Aluno *));

	if (!tmp) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	vd->v = tmp;
}

void vd_insere(VetorDin * vd, char *nome, float p1, float p2, float p3)
{
	if (vd->n == vd->nmax) {
		realoca(vd);
	}
	Aluno *a = aluno_cria(nome, p1, p2, p3);
	vd->v[vd->n++] = a;
}

int vd_tam(VetorDin * vd)
{
	return vd->n;
}

Aluno *vd_acessa(VetorDin * vd, int i)
{
	assert(i >= 0 && i < vd->n);
	return vd->v[i];
}

void vd_libera(VetorDin * vd)
{
	for (int i = 0; i < vd->n; i++) {
		aluno_libera(vd->v[i]);
	}
	free(vd->v);
	free(vd);
}
