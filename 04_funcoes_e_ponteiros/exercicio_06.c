/*
 * Implemente uma função que receba como parâmetro dois números inteiros n e k, e
 * calcule o coeficiente binomial C(n,k) correspondente, definido pela seguinte relação
 * recursiva:
 *
 *              C(n,0) = C(n,n) = 1                             para n >= 0
 *              C(n,k) = C(n - 1,k) + C(n - 1,k - 1)           para n > k > 0
 *
 * O protótipo dessa função deve ser:
 *
 *      int coeficiente (int n, int k);
 */

int coeficiente(int n, int k)
{
	if (n < k) {
		return -1;
	}

	if (n == k || 0 == k) {
		return 1;
	}
	return coeficiente(n - 1, k) + coeficiente(n - 1, k - 1);
}
