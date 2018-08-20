/*
 * Escreva uma função que receba um vetor de inteiros e tenha como valor de retorno
 * um novo vetor, alocado dinamicamente, apenas com os elementos pares do vetor
 * original. A função deve ter como valor de retorno o ponteiro do vetor alocado e
 * preencher o endereço de memória passado com a dimensão do novo vetor, seguindo
 * o protótipo:
 *
 *      int* somente_pares (int n, int* v, int* npares);
 */

#include <stdio.h>
#include <stdlib.h>

static void check(void *p)
{
	if (!p) {
		perror("Erro:");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

int *somente_pares(int n, int *v, int *npares)
{
	int *pares;
	*npares = 0;
	for (int i = 0; i < n; i++) {
		if (!(v[i] % 2)) {
			(*npares)++;
		}
	}
	pares = (int *)aloca((*npares) * sizeof(int));
	for (int i = 0, k = 0; i < n; i++) {
		if (!(v[i] % 2)) {
			pares[k] = v[i];
			k++;
		}
	}
	return pares;
}

static void popula(int n, int *v)
{
	puts("Entre com os valores:");
	for (int i = 0; i < n; i++) {
		scanf("%d", v + i);
	}
}

static void imprime(int n, int *v, char *fmt, char *end)
{
	for (int i = 0; i < n; i++) {
		printf(fmt, v[i]);
	}
	printf(end);
}

int main(void)
{
	int *v, *pares;
	int n, npares;
	while (1) {
		printf("Entre com o tamanho do vetor: ");
		scanf("%d", &n);
		v = (int *)aloca(n * sizeof(int));
		popula(n, v);
		pares = somente_pares(n, v, &npares);
		imprime(npares, pares, "%d ", "\n");
		free(pares);
	}
	return 0;
}
