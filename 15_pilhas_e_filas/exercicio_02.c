/*
 * Considere a existência de um tipo abstrato Fila de números reais, cuja interface
 * está definida no arquivo "fila.h" da seguinte forma:
 *
 *	typedef struct fila Fila;
 *	Fila* fila_cria (void);
 *	void fila_insere (Fila* f, float v);
 *	float fila_retira (Fila* f);
 *	int fila_vazia (Fila* f);
 *	void fila_libera (Fila* f);
 *
 *	Sem conhecer a representação interna desse tipo abstrato e usando apenas as fun-
 *	ções declaradas no arquivo de interface, implemente uma função que receba três
 *	filas, f_res, f1 e f2, e transfira alternadamente os elementos de f1 e f2 para
 *	f_res, conforme ilustrado na Figura 15.7.
 *
 *	(Figura no livro)
 *
 *	Note que, ao final dessa função, as filas f1 e f2 vão estar vazias e a fila f_res vai
 *	conter todos os valores que estavam originalmente em f1 e f2 (inicialmente f_res
 *	pode ou não estar vazia). Se uma fila for maior que a outra, os valores excedentes
 *	devem ser transferidos para a nova fila no final. Essa função deve obedecer ao
 *	protótipo:
 *
 *		void combina_filas (Fila* f_res, Fila* f1, Fila* f2);
 */

void combina_filas(Fila * f_res, Fila * f1, Fila * f2)
{
	while (!fila_vazia(f1) && !fila_vazia(f2)) {
		fila_insere(f_res, fila_retira(f1));
		fila_insere(f_res, fila_retira(f2));
	}
	while (!fila_vazia(f1)) {
		fila_insere(f_res, fila_retira(f1));
	}
	while (!fila_vazia(f2)) {
		fila_insere(f_res, fila_retira(f2));
	}
}
