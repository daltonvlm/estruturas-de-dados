/*
 * Implemente um função que tenha como valor de retorno o comprimento de uma
 * lista encadeada, isto é, que calcule o número de nós de uma lista. Essa função deve
 * obedecer ao protótipo:
 *
 * 		int comprimento (Lista* l);
 */

int comprimento(Lista * l)
{
	int n = 0;
	for (ListaNo * p = l->prim; p; p = p->prox) {
		n++;
	}
	return n;
}
