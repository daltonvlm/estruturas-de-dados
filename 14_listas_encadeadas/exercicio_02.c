/*
 * Considerando listas encadeadas de valores inteiros, implemente uma função que
 * retorne o número de nós da lista que possuem o campo info com valores maiores
 * do que x. Essa função deve obedecer ao protótipo:
 *
 * 		int maiores (Lista *l, int x);
 */

int maiores(Lista * l, int x)
{
	int n = 0;
	for (ListaNo * p = l->prim; p; p = p->prox) {
		if (p->info > x) {
			n++;
		}
	}
	return n;
}
