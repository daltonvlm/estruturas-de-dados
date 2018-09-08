/*
 * Implemente uma função que retorne o número de nós folhas maiores do que um
 * valor x, considerando uma árvore binária de busca. Essa função deve obedecer ao
 * protótipo:
 *
 * 		int nfolhas_maiores (Arv* a, int x);
 */

static int arvno_nfolhas_maiores(ArvNo * r, int x)
{
	if (r) {
		int n = (!r->esq && !r->dir
			 && r->info > x) + arvno_nfolhas_maiores(r->dir, x);
		if (x <= r->info) {
			n += arvno_nfolhas_maiores(r->esq, x);
		}
		return n;
	}
	return 0;
}

int nfolhas_maiores(Arv * a, int x)
{
	return arvno_nfolhas_maiores(a->raiz, x);
}
