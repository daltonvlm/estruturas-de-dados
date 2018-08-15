/*
 * Para haver percolação através de um meio poroso (por exemplo, uma rocha), é
 * necessário existir um canal de comunicação dos poros para a passagem do fluido.
 * Sabe-se que, em sistemas reticulares, nos quais os poros têm distribuição uniforme
 * e aleatória, a porosidade (taxa de "vazios") mínima do meio para haver percolação
 * é 0.592746. Apesar de não existir um modelo matemático que comprove este valor
 * lmite, podemos comprová-lo através de um modelo numérico. Veja a Figura 21.7.
 * A ideia é criar uma grade reticulada subdividindo o meio que, no início, está total-
 * mente fechado. As células da primeira camada são abertas e conectadas; as células
 * da última camada também são abertas e conectadas. O objetivo é determinar a
 * porosidadde mínima para que as duas partições (da camada superior e da camada
 * inferior) sejam unidas. De forma randômica, escolha uma célula e a transforme em
 * espaço vazio, conectando as eventuais células vazias adjacentes. Este processo é
 * repetido até que se tenha uma conexão entere as células superiores e as células in-
 * feriores. Faça um programa que implemente este experimento (usando a estrutura
 * união-e-busca) e comprove (dentro de um grau de tolerância) a veracidade do valor
 * limite informado. Quanto maior a resolução da grade, maior a precisão do valor
 * encontrado.
 *
 * 	Adaptação da figura do livro:
 *
 * 		+---+---+---+---+---+---+---+---+---+---+
 * 		| F |   |   |   |   |   |   |   |   | F |
 * 		+---+---+---+---+---+---+---+---+---+---+
 * 		| F | X | X | X | X | X | X | X | X | F |
 * 		+---+---+---+---+---+---+---+---+---+---+
 * 		| F | X | X | X | X | X | X | X | X | F |
 * 		+---+---+---+---+---+---+---+---+---+---+
 * 		| F | X | X | X | X | X | X | X | X | F |		+---+
 * 		+---+---+---+---+---+---+---+---+---+---+		| F |= células de bordas fixas
 * 		| F | X | X | X | X | X | X | X | X | F |		+---+
 * 		+---+---+---+---+---+---+---+---+---+---+		+---+
 * 		| F | X | X | X | X | X | X | X | X | F |		| X |= células de bordas ocupadas
 * 		+---+---+---+---+---+---+---+---+---+---+		+---+
 * 		| F | X | X | X | X | X | X | X | X | F |		+---+
 * 		+---+---+---+---+---+---+---+---+---+---+		|   |= células inicialmente abertas e 
 * 		| F | X | X | X | X | X | X | X | X | F |		+---+  conectadas
 * 		+---+---+---+---+---+---+---+---+---+---+
 * 		| F | X | X | X | X | X | X | X | X | F |
 * 		+---+---+---+---+---+---+---+---+---+---+
 * 		| F |   |   |   |   |   |   |   |   | F |
 * 		+---+---+---+---+---+---+---+---+---+---+
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uniaobusca.h"

#define INDEX(nx,i,j) ((i)*(nx)+(j))

#define LIN_MIN 3
#define LIN_MAX 15
#define COL_MIN 1
#define COL_MAX 25

typedef struct {
	int nx, ny;
	int poros;
	int **mat;
	UniaoBusca *ub;
} Grade;

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

void grade_une_adjacentes(Grade * g, int i, int j)
{
	int p = ub_busca(g->ub, INDEX(g->nx, i, j));

	if (i - 1 >= 0 && g->mat[i - 1][j]) {
		int q = ub_busca(g->ub, INDEX(g->nx, i - 1, j));
		ub_uniao(g->ub, p, q);
	}

	if (i + 1 < g->ny && g->mat[i + 1][j]) {
		int q = ub_busca(g->ub, INDEX(g->nx, i + 1, j));
		ub_uniao(g->ub, p, q);
	}

	if (j - 1 >= 0 && g->mat[i][j - 1]) {
		int q = ub_busca(g->ub, INDEX(g->nx, i, j - 1));
		ub_uniao(g->ub, p, q);
	}

	if (j + 1 < g->nx && g->mat[i][j + 1]) {
		int q = ub_busca(g->ub, INDEX(g->nx, i, j + 1));
		ub_uniao(g->ub, p, q);
	}
}

Grade *grade_cria(int nx, int ny)
{
	Grade *g = (Grade *) aloca(sizeof(Grade));
	g->nx = nx;
	g->ny = ny;
	g->poros = 2 * g->nx;
	g->ub = ub_cria(g->nx * g->ny);
	g->mat = (int **)aloca(g->ny * sizeof(int *));

	// aloca matriz de poros
	for (int i = 0; i < g->ny; i++) {
		g->mat[i] = (int *)aloca(g->nx * sizeof(int));

		// define os poros como fechados
		for (int j = 0; j < g->nx; j++) {
			g->mat[i][j] = 0;
		}
	}

	// define os poros da primeira e ultima linha como abertos
	for (int k = 0; k < g->nx; k++) {
		g->mat[0][k] = 1;
		g->mat[g->ny - 1][k] = 1;
	}

	// une poros abertos
	for (int k = 0; k < g->nx - 1; k++) {
		grade_une_adjacentes(g, 0, k);
		grade_une_adjacentes(g, g->ny - 1, k);
	}
	return g;
}

void grade_libera(Grade * g)
{
	ub_libera(g->ub);
	for (int i = 0; i < g->ny; i++) {
		free(g->mat[i]);
	}
	free(g->mat);
	free(g);
}

int grade_verifica_percolacao(Grade * g)
{
	return ub_busca(g->ub, INDEX(g->nx, 0, 0))
	    == ub_busca(g->ub, INDEX(g->nx, g->ny - 1, 0));
}

void grade_imprime(Grade * g)
{
	for (int i = 0; i < g->nx + 2; i++) {
		printf("+---");
	}
	puts("+");

	for (int i = 0; i < g->ny; i++) {
		printf("| X |");
		for (int j = 0; j < g->nx; j++) {
			printf(" %c |", g->mat[i][j] ? ' ' : 'X');
		}
		puts(" X |");

		printf("+");
		for (int k = 0; k < g->nx + 2; k++) {
			printf("---+");
		}
		puts("");
	}
}

void grade_adiciona_poro(Grade * g, int i, int j)
{
	if (!g->mat[i][j]) {
		g->poros++;
		g->mat[i][j] = 1;
		grade_une_adjacentes(g, i, j);
	}
}

int grade_pega_celulas(Grade * g)
{
	return g->nx * g->ny;
}

int grade_pega_poros(Grade * g)
{
	return g->poros;
}

int main(void)
{
	srand(time(NULL));
	while (1) {
		int nx = COL_MIN + rand() % (COL_MAX - COL_MIN) + 1;
		int ny = LIN_MIN + rand() % (LIN_MAX - LIN_MIN) + 1;

		int celulas, poros;
		Grade *g = grade_cria(nx, ny);

		while (!grade_verifica_percolacao(g)) {
			int i = rand() % ny;
			int j = rand() % nx;
			grade_adiciona_poro(g, i, j);
		}
		grade_imprime(g);

		celulas = grade_pega_celulas(g);
		poros = grade_pega_poros(g);
		printf("Celulas: %d\n", celulas);
		printf("Poros: %d\n", poros);
		printf("Taxa de porosidade: %f\n", (double)poros / celulas);

		grade_libera(g);
		getchar();
	}
	return 0;
}
