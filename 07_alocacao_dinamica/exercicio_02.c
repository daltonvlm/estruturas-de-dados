/*
 * Escreva uma função que receba um vetor de inteiros e tenha como valor de retorno
 * um novo vetor, alocado dinamicamente, apenas com os elementos pares do vetor
 * original. A função deve ter como valor de retorno o ponteiro do vetor alocado e
 * preencher o endereço de memória passado com a dimensão do novo vetor, seguindo
 * o protótipo:
 *
 *      int* somente_pares (int n, int* v, int* npares);
 */

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro:");
		exit(EXIT_FAILURE);
	}
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
