#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vetordin_aluno.h"

struct vetordin_aluno {
	int n;
	int nmax;
	Aluno **v;
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

VDAluno *vda_cria(void)
{
	VDAluno *vda = (VDAluno *) aloca(sizeof(VDAluno));
	vda->n = 0;
	vda->nmax = 4;
	vda->v = (Aluno **) aloca(vda->nmax * sizeof(Aluno *));
	return vda;
}

static void realoca(VDAluno * vda)
{
	vda->nmax *= 2;
	vda->v = (Aluno **) realloc(vda->v, vda->nmax * sizeof(Aluno *));
	if (!vda->v) {
		perror("");
		exit(EXIT_FAILURE);
	}
}

void vda_insere(VDAluno * vda, Aluno * a)
{
	if (vda->n == vda->nmax) {
		realoca(vda);
	}
	vda->v[vda->n++] = a;
}

int vda_tam(VDAluno * vda)
{
	return vda->n;
}

Aluno *vda_acessa(VDAluno * vda, int i)
{
	assert(i >= 0 && i < vda->n);
	return vda->v[i];
}

void vda_libera(VDAluno * vda, int libera_alunos)
{
	if (libera_alunos) {
		for (int i = 0; i < vda->n; i++) {
			aluno_libera(vda->v[i]);
		}
	}
	free(vda->v);
	free(vda);
}
