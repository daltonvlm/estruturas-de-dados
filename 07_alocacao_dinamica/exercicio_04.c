/*
 * Repita as implementações do exercício anterior para uma matriz triangular supe-
 * rior. Nota: é mais fácil alocar os elementos abaixo da diagonal, e usar o acesso
 * transposto aos elementos.
 */

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

float **ts_cria(int n)
{
	float **mat = (float **)aloca(n * sizeof(float *));
	for (int i = 0; i < n; i++) {
		mat[i] = (float *)aloca((i + 1) * sizeof(float));
		for (int j = 0; j <= i; j++) {
			mat[i][j] = 0;
		}
	}
	return mat;
}

void ts_atribui(int i, int j, float x, float **mat)
{
	if (i <= j) {
		mat[j][i] = x;
	}
}

float ts_acessa(int i, int j, float **mat)
{
	return i <= j ? mat[j][i] : 0;
}

void ts_libera(int n, float **mat)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}
