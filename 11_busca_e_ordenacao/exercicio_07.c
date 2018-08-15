/*
 * Altere o algoritmo de ordenação rápida discutido, aplicado a um vetor de inteiros,
 * para que use como pivô o valor mediano entre o primeiro, o último e o elemento do
 * meio do vetor. Neste caso, se o vetor tiver apenas dois elementos, deve-se colocá-los
 * em ordem sem chamar a função recursivamente. Para facilitar a adaptação do algo-
 * ritmo apresentado, pode-se usar a seguinte estratégia: ache o valor mediano entre
 * os três elementos, troque o valor do elemento mediano com o primeiro elemento (se
 * o primeiro já não for o mediano) e execute o mesmo procedimento usando o pri-
 * meiro elemento como pivô da partição. Esta estratégia para escolher o pivô tende a
 * melhorar substancialmente o desempenho do algoritmo na prática, pois, em geral,
 * resulta em partições mais equilibradas.
 */

#include <stdio.h>

void quick_sort(int n, int *v);
void quick_sort_modificado(int n, int *v);

int main(void)
{
	int v[] = { 9, 0, 8, 1, 7, 2, 6, 3, 5, 4 };
	quick_sort_modificado(10, v);

	for (int i = 0; i < 10; i++) {
		printf("%d ", v[i]);
	}
	puts("");
	return 0;
}

static int mediano(int a, int b, int c)
{
	int v[] = { a, b, c };

	for (int i = 2; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				int t = v[j];
				v[j] = v[j + 1];
				v[j + 1] = t;
			}
		}
	}
	return v[1];
}

void quick_sort(int n, int *v)
{
	if (n < 2) {
		return;
	}
	int a = 1;
	int b = n - 1;

	while (a < b) {
		while (a < n && v[a] <= v[0]) {
			a++;
		}
		while (v[b] > v[0]) {
			b--;
		}
		if (a < b) {
			int t = v[a];
			v[a] = v[b];
			v[b] = t;
		}
	}
	int t = v[0];
	v[0] = v[b];
	v[b] = t;

	quick_sort_modificado(b, v);
	quick_sort_modificado(n - a, v + a);
}

void quick_sort_modificado(int n, int *v)
{
	if (n > 2) {
		int m = mediano(0, n / 2, n - 1);
		if (m != 0) {
			int t = v[0];
			v[0] = v[m];
			v[m] = t;
		}
	}
	quick_sort(n, v);
}
