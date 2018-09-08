/*
 * Implemente uma função que transforma uma lista simplesmente encadeada numa
 * lista circular. O protótipo da função deve ser:
 *
 * 		void para_circular (Lista *l);
 */

void para_circular(Lista * l)
{
	ListaNo *p = l->prim;
	if (p) {
		for (; p->prox; p = p->prox) {
			;
		}
		p->prox = l->prim;
	}
}
