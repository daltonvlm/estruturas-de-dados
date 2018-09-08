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

static void ajusta_pivo(int n, int *v)
{
	int p[] = { 0, n / 2, n - 1 };

	puts("Ajustando pivo:");
	imprime(n, v);
	for (int i = 2; i; i--) {
		for (int j = 0; j < i; j++) {
			if (v[p[j]] > v[p[j + 1]]) {
				int t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
			}
		}
	}
	if (p[1]) {
		int t = v[0];
		v[0] = v[p[1]];
		v[p[1]] = t;
	}
	imprime(n, v);
}

void rapida(int n, int *v)
{
	if (n < 2) {
		return;
	}
	if (2 == n) {
		if (v[0] > v[1]) {
			int t = v[0];
			v[0] = v[1];
			v[1] = t;
		}
		return;
	}
	ajusta_pivo(n, v);
	int a = 1;
	int b = n - 1;
	int x = v[0];
	do {
		while (v[a] <= x && a < n) {
			a++;
		}
		while (v[b] > x) {
			b--;
		}
		if (a < b) {
			int t = v[a];
			v[a] = v[b];
			v[b] = t;
			a++;
			b--;
		}
	} while (a <= b);
	v[0] = v[b];
	v[b] = x;
	rapida(b, v);
	rapida(n - a, v + a);
}
