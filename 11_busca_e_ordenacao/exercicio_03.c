/*
 * Considere um vetor de inteiros cujos valores estão armazenados em ordem crescente.
 * Usando como base o algoritmo de busca binária, escreva uma função que, dado o
 * vetor e um valor inteiro x, retorne o elemento do vetor que possui valor mais próximo
 * de x. Caso x seja equidistante de dois elementos do vetor, sua função deve retornar
 * o valor do menor deles. Por exemplo, considerando o vetor {3,7,10,14,16}, sua
 * função deve retornar os valores indicados a seguir para os diferentes casos listados:
 *
 * 			-------------------------------------
 * 			|	Valor de x	|	Valor retornado	|
 * 			|		11		|		10			|
 * 			|		5		|		3			|
 * 			|		14		|		14			|
 * 			|		13		|		14			|
 * 			-------------------------------------
 *
 * Considere que o valor de x é maior ou igual ao primeiro elemento do vetor e menor
 * ou igual ao último elemento do vetor. Sua função deve ter o seguinte protótipo:
 *
 * 		int mais_proximo (int n, int* vet, int x);
 */

int mais_proximo(int n, int *vet, int x)
{
	int i = 0;
	int f = n - 1;

	while (i < f) {
		int m = (i + f) / 2;

		if (x <= vet[m]) {
			if (!m) {
				return vet[m];
			}
			int a = x - vet[m - 1];
			int b = vet[m] - x;

			if (a > b) {
				return vet[m];
			}
			f = m - 1;
		} else {
			if (m == n - 1) {
				return vet[m];
			}
			int a = x - vet[m];
			int b = vet[m + 1] - x;

			if (a <= b) {
				return vet[m];
			}
			i = m + 1;
		}
	}
	return vet[i];
}
