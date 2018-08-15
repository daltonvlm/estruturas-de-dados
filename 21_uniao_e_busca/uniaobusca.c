#include <stdio.h>
#include <stdlib.h>
#include "uniaobusca.h"

struct uniaobusca {
	int n;
	int *v;
};

static void check(void *p)
{
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

UniaoBusca *ub_cria(int n)
{
	UniaoBusca *ub = (UniaoBusca *) aloca(sizeof(UniaoBusca));
	ub->n = n;
	ub->v = (int *)aloca(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		ub->v[i] = -1;
	}
	return ub;
}

void ub_libera(UniaoBusca * ub)
{
	free(ub->v);
	free(ub);
}

int ub_busca(UniaoBusca * ub, int x)
{
	int r = x;
	while (ub->v[r] >= 0) {
		r = ub->v[r];
	}
#ifdef QTD_NOS
	while (ub->v[x] >= 0) {
		int p = ub->v[x];
		ub->v[x] = r;
		x = p;
	}
#endif
	return r;
}

int ub_uniao(UniaoBusca * ub, int x, int y)
{
	x = ub_busca(ub, x);
	y = ub_busca(ub, y);

	if (x == y) {
		return x;
	}
#ifdef QTD_NOS
	if (ub->v[x] <= ub->v[y]) {
		ub->v[x] += ub->v[y];
		ub->v[y] = x;
		return x;
	}
	ub->v[y] += ub->v[x];
	ub->v[x] = y;
#else
	if (ub->v[x] < ub->v[y]) {
		ub->v[y] = x;
	} else if (ub->v[x] > ub->v[y]) {
		ub->v[x] = y;
	} else {
		ub->v[x] -= 1;
		ub->v[y] = x;
	}
#endif
	return y;
}
