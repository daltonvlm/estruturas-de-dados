#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

typedef struct vertice Vertice;
typedef struct aresta Aresta;

typedef enum vcor Vcor;
enum vcor {
	BRANCO = 0,		// nao explorado
	CINZA,			// sendo explorado
	PRETO			// explorado
};

typedef enum atipo ATipo;
enum atipo {
	ARVORE,
	TRAS,
	OUTRA			// Cruzada ou Afrente
};

struct vertice {
	Aresta *lista;
	Vcor cor;
	int ti;			// tempo inicial
	int tf;			// tempo final
	int vant;		// vertice anterior
	float custo;
};

struct aresta {
	int v;
	Aresta *prox;
	ATipo tipo;
};

struct grafo {
	int n;
	int carimbo;
	Vertice *v;
};

static void initempo(Grafo * g)
{
	g->carimbo = 0;
}

static int tempo(Grafo * g)
{
	return g->carimbo++;
}

static void inicializa(Grafo * g)
{
	initempo(g);
	for (int i = 0; i < g->n; i++) {
		g->v[i].ti = -1;
		g->v[i].tf = -1;
		g->v[i].cor = BRANCO;
		g->v[i].vant = -1;
	}
}

static void idfs(Grafo * g, int i)
{
	g->v[i].cor = CINZA;
	g->v[i].ti = tempo(g);
	for (Aresta * a = g->v[i].lista; a; a = a->prox) {
		int j = a->v;
		if (BRANCO == g->v[j].cor) {
			g->v[j].vant = i;
			a->tipo = ARVORE;
			idfs(g, j);
		} else if (CINZA == g->v[i].cor) {
			a->tipo = TRAS;
		} else {
			a->tipo = OUTRA;
		}
	}
	g->v[i].cor = PRETO;
	g->v[i].tf = tempo(g);
}

void grafo_dfs(Grafo * g, int v)
{
	inicializa(g);
	idfs(g, v);
}

void grafo_bfs(Grafo * g, int v)
{
	Fila *q = fila_cria();
	fila_insere(q, v);

	inicializa(g);

	g->v[v].ti = tempo(g);
	g->v[v].cor = CINZA;
	g->v[v].custo = .0f;

	while (!fila_vazia(q)) {
		int i = fila_retira(q);

		for (Aresta * a = g->v[i].lista; a; a = a->prox) {
			int j = a->v;

			if (BRANCO == g->v[j].cor) {
				g->v[j].vant = i;
				g->v[j].custo = g->v[i].custo + 1;
				g->v[j].ti = tempo(g);
				g->v[j].cor = CINZA;
				a->tipo = ARVORE;
				fila_insere(q, j);

			} else{
				a->tipo=OUTRA;
			}
		}
		g->v[i].cor = PRETO;
		g->v[i].tf = tempo(g);
	}
	fila_libera(q);
}
