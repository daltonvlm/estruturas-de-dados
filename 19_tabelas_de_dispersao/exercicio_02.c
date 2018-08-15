/*
 * Implemente um código para fazer uma análise do desempenho de funções de busca,
 * comparando busca binária em vetor e busca em tabela de dispersão. O experimento
 * pode ser feito usando valores inteiros: buscar um valor inteiro em um vetor ordenado
 * versus buscar um valor inteiro em uma tabela de dispersão. Considerando que n
 * representa o número de valores inteiros, crie um vetor desta dimensão e uma tabela
 * de dispersão (pode-se já predefinir a tabela com o dobro do tamanho para evitar
 * redimensionamento). Gere aleatoriamente n valores inteiros usando a função rand;
 * insira o valor gerado no vetor e na tabela de dispersão; ao final, ordene o vetor.
 * Então, repita a geração dos n valores. Para garantir que a mesma sequência de
 * valores seja gerada, use um mesmo valor de semente (por exemplo, chamando
 * srand (0) antes de gerar o primeiro número de cada sequência). Para cada valor,
 * busque o valor no vetor usando busca binária. Para medir o tempo gasto para
 * fazer a busca dos n valores, use a função clock da biblioteca time.h, que reporta
 * o tempo de CPU gasto desde a invocação do processo (isto é, desde o início da
 * execução do programa), medidos em clocks por segundo ( CLOCKS_PER_SEC, uma
 * constante também definida em time.h). Interessa-nos a diferença de tempo de
 * CPU entre o início e o fim do procedimento que queremos medir. Em seguida,
 * repita o mesmo procedimento, gerando e buscando os n valores agora na tabela de
 * dispersão, medindo o tempo de execução. Imprima e compare os tempos de busca
 * de cada estratégia. Use diferentes valores de n e verifique a eficiência da tabela de
 * dispersão. O trecho de código a seguir ilustra a tomada de tempo de execução de
 * um procedimento.
 *
 * 		clock_t t0 = clock();
 *
 * 		... // procedimento que se deseja medir tempo de execução
 *
 * 		clock_t t1 = clock();
 * 		double t = (double)(t1-t0)/CLOCKS_PER_SEC; // tempo (seg)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct hash Hash;
typedef struct elemento Elemento;

struct hash {
	int n;
	Elemento **v;
};

struct elemento {
	int x;
	Elemento *prox;
};

int hash(Hash * tab, int x)
{
	return abs(x % tab->n);
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

Hash *hash_cria(int n)
{
	Hash *tab = (Hash *) aloca(sizeof(Hash));
	tab->n = 2.0973 * n;
	tab->v = (Elemento **) aloca(tab->n * sizeof(Elemento *));
	memset(tab->v, 0, tab->n * sizeof(Elemento *));
	return tab;
}

void hash_insere(Hash * tab, int x)
{
	int h = hash(tab, x);

	for (Elemento * e = tab->v[h]; e; e = e->prox) {
		if (e->x == x) {
			return;
		}
	}
	Elemento *e = (Elemento *) aloca(sizeof(Elemento));
	e->x = x;
	e->prox = tab->v[h];
	tab->v[h] = e;
}

int *hash_busca(Hash * tab, int x)
{
	int h = hash(tab, x);

	for (Elemento * e = tab->v[h]; e; e = e->prox) {
		if (e->x == x) {
			return &e->x;
		}
	}
	return NULL;
}

void hash_libera(Hash * tab)
{
	for (int i = 0; i < tab->n; i++) {
		Elemento *e = tab->v[i];
		while (e) {
			Elemento *t = e;
			e = e->prox;
			free(t);
		}
	}
	free(tab->v);
	free(tab);
}

static double tempo_hash(int n)
{
	Hash *tab = hash_cria(n);
	clock_t ti, tf;

	srand(0);
	for (int i = 0; i < n; i++) {
		hash_insere(tab, rand());
	}

	srand(0);
	ti = clock();
	for (int i = 0; i < n; i++) {
		int *p = hash_busca(tab, rand());
		printf("%d\n", *p);
	}
	tf = clock();
	hash_libera(tab);

	return (double)(tf - ti) / CLOCKS_PER_SEC;
}

static int cmp(const void *v1, const void *v2)
{
	int *p = (int *)v1;
	int *q = (int *)v2;
	return *p - *q;
}

static double tempo_vet(int n)
{
	int *v = (int *)aloca(n * sizeof(int));
	clock_t ti, tf;

	srand(0);
	for (int i = 0; i < n; i++) {
		v[i] = rand();
	}
	qsort(v, n, sizeof(int), cmp);

	srand(0);
	ti = clock();
	for (int i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}
	tf = clock();
	free(v);

	return (double)(tf - ti) / CLOCKS_PER_SEC;
}

int main(void)
{
	int min = 100;
	int max = 1001;

	while (1) {
		srand(time(NULL));

		int n = rand() % (max - min) + min;
		double thash = tempo_hash(n);
		double tvet = tempo_vet(n);

		printf("Tempo de busca de %d elementos:\n", n);
		printf("Hash: %f segundos.\n", thash);
		printf("Vetor: %f segundos.\n", tvet);
		getchar();
	}
	return 0;
}
