/*
 * Implemente uma função que receba como parâmetros um vetor de números inteiros
 * v e seu número de elementos n, e verifique se os elementos do vetor correspondem aos
 * termos de uma PA (progressão aritmética), isto é, se existe um número inteiro k tal
 * que v[i] seja igual a v[0] + i*k. Caso os elementos do vetor correspondam aos
 * termos de uma PA, a função deve retornar o valor calculado para k. Por exemplo,
 * se for passado para essa função o vetor {2,10,18,26,34}, ela deve retornar o valor
 * 8. Caso o vetor não corresponda a uma PA, a função deve retornar 0. Assuma
 * que o vetor sempre terá pelo menos três elementos. Tal função deve ter o seguinte
 * protótipo:
 *
 *      int testa_PA (int n, int *v);
 */

/* A questão apresenta um erro conceitual, pois uma sequência constituida de 0s é também
 * uma PA. No entanto, da maneira como a questão está formulada, um retorno de 0 implicaria
 * que a sequência não constitui uma PA.
 */

int testa_PA(int n, int *v)
{
	int k = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		if (v[i] != v[0] + i * k) {
			return 0;
		}
	}
	return k;
}
