/*
 * Implemente uma função que retorne a quantidade de folhas de uma árvore binária.
 * Essa função deve obedecer ao protótipo:
 *
 * 		int folhas (Arv* a);
 */

static int no_folhas(ArvNo * r)
{
	if (!r) {
		return 0;
	}
	return (!r->esq && !r->dir) + no_folhas(r->esq) + no_folhas(r->dir);
}

int folhas(Arv * a)
{
	return no_folhas(a->raiz);
}
