/*
 * Escreva uma função que, dadas duas matrizes quadradas, A e B, verifique se B é
 * a inversão de A, isto é, se B é igual a A^-1. Se B for a inversa, a multiplicação de A
 * por B resulta numa matriz identidade. A função deve retornar 1 se B é a inversa
 * de A e 0 caso contrário, e deve seguir e seguinte protótipo:
 *
 *      int inversa (double A[][N], double B[][N]);
 */

static void produto_matriz(double A[][N], double B[][N], double C[][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = 0;
			for (int k = 0; k < N; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

static int identidade(double A[][N])
{
	for (int i = 0; i < N; i++) {
		if (A[i][i] != 1) {
			return 0;
		}
		for (int j = 0; j < i; j++) {
			if (A[i][j] || A[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

int inversa(double A[][N], double B[][N])
{
	double C[N][N];
	produto_matriz(A, B, C);
	return identidade(C);
}
