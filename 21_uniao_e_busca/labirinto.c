#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uniaobusca.h"
#include "labirinto.h"

#define INDEX(m,i,j) ((i)*(m->nx)+(j))

typedef struct parede Parede;
struct parede {
	int i, j;		// celula
	int r;			// numero randomico associado
	int w;			// orientacao: 0 vertical; 1 horizontal
	int f;			// visibilidade
};

struct labirinto {
	int nx, ny;		// numero de celulas
	int n;			// numero de paredes
	Parede *v;
	UniaoBusca *ub;
};

static int compparede(const void *p1, const void *p2)
{
	Parede *w1 = (Parede *) p1;
	Parede *w2 = (Parede *) p2;
	return w1->r - w2->r;
}

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

static void inicializa(Labirinto * m)
{
	m->ub = ub_cria(m->nx * m->ny);
	m->n = (m->nx - 1) * m->ny + (m->ny - 1) * m->nx;
	m->v = (Parede *) aloca(m->n * sizeof(Parede));

	srand(time(NULL));

	int k = 0;
	for (int i = 0; i < m->ny; i++) {
		for (int j = 0; j < m->nx; j++) {
			if (i != m->ny - 1) {
				m->v[k].i = i;
				m->v[k].j = j;
				m->v[k].w = 1;
				m->v[k].f = 1;
				m->v[k].r = rand();
				k++;
			}
			if (j != m->nx - 1) {
				m->v[k].i = i;
				m->v[k].j = j;
				m->v[k].w = 0;
				m->v[k].f = 1;
				m->v[k].r = rand();
				k++;
			}
		}
	}
	qsort(m->v, m->n, sizeof(Parede), compparede);
}

Labirinto *labirinto_cria(int nx, int ny)
{
	Labirinto *m = (Labirinto *) aloca(sizeof(Labirinto));
	m->nx = nx;
	m->ny = ny;
	inicializa(m);

	for (int k = 0; k < m->n; k++) {
		int i = m->v[k].i;
		int j = m->v[k].j;
		int c1, c2;

		// parede horizontal
		if (m->v[k].w) {
			c1 = ub_busca(m->ub, INDEX(m, i, j));
			c2 = ub_busca(m->ub, INDEX(m, i + 1, j));

			// parede vertical
		} else {
			c1 = ub_busca(m->ub, INDEX(m, i, j));
			c2 = ub_busca(m->ub, INDEX(m, i, j + 1));
		}

		if (c1 != c2) {
			ub_uniao(m->ub, c1, c2);
			m->v[k].f = 0;
		}
	}
	return m;
}

void labirinto_libera(Labirinto * m)
{
	ub_libera(m->ub);
	free(m->v);
	free(m);
}

void labirinto_imprime(Labirinto * m)
{
	int *hparedes = (int *)aloca(m->nx * m->ny * sizeof(int));
	int *vparedes = (int *)aloca(m->nx * m->ny * sizeof(int));

	for (int k = 0; k < m->nx * m->ny; k++) {
		hparedes[k] = 1;
		vparedes[k] = 1;
	}

	for (int k = 0; k < m->n; k++) {

		// parede invisivel
		if (!m->v[k].f) {
			int i = m->v[k].i;
			int j = m->v[k].j;

			// parede horizontal
			if (m->v[k].w) {
				hparedes[INDEX(m, i, j)] = 0;
			} else {
				vparedes[INDEX(m, i, j)] = 0;
			}
		}
	}
	hparedes[m->nx * m->ny - 1] = 0;

	// imprime parede superior
	printf("+   ");
	for (int i = 1; i < m->nx; i++) {
		printf("+---");
	}
	puts("+");

	for (int i = 0; i < m->ny; i++) {

		// imprime paredes verticais
		printf("|");
		for (int j = 0; j < m->nx; j++) {
			printf("   ");
			if (vparedes[INDEX(m, i, j)]) {
				printf("|");
			} else {
				printf(" ");
			}
		}
		puts("");

		// imprime paredes horizontais
		printf("+");
		for (int j = 0; j < m->nx; j++) {
			if (hparedes[INDEX(m, i, j)]) {
				printf("---+");
			} else {
				printf("   +");
			}
		}
		puts("");
	}
	free(hparedes);
	free(vparedes);
}
