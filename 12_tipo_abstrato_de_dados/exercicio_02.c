/*
 * Usando apenas as operações definidas pela TAD Matriz, implemente uma função
 * que, dada uma matriz, cria dinamicamente a matriz transposta correspondente.
 */

static Matriz *mat_transp(Matriz * mat)
{
	int lin = mat_colunas(mat);
	int col = mat_linhas(mat);
	Matriz *tp = mat_cria(lin, col);
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			float x = mat_acessa(mat, j, i);
			mat_atribui(tp, i, j, x);
		}
	}
	return tp;
}
