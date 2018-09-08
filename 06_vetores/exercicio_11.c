/*
 * Escreva uma função que verifique se uma matriz quadrada de dimensão N x N,
 * onde N representa uma constante simbólica, é uma matriz triangular inferior. Numa
 * matriz triangular inferior, todos os elementos acima da diagonal principal são iguais
 * a 0.0. Os elementos da diagonal ou abaixo da diagonal podem assumir valores
 * quaisquer. A função deve retornar 1 se a matriz dada for triangular inferior e 0
 * caso contrário, e deve seguir o seguinte protótipo:
 *
 *      int triangular_inferior (double A[][N]);
 */

int triangular_inferior(double A[][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}
