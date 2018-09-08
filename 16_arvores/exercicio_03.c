/*
 * Implemente uma função que retorne a quantidade de nós de uma árvore binária
 * que possuem apenas um filho. Essa função deve obedecer ao protótipo:
 *
 * 		int um_filho (Arv *a);
 */

static int arvno_um_filho(ArvNo * r)
{
	if (!r || !r->dir && !r->esq) {
		return 0;
	}
	return !(r->esq
		 && r->dir) + arvno_um_filho(r->esq) + arvno_um_filho(r->dir);
}

int um_filho(Arv * a)
{
	return arvno_um_filho(a->raiz);
}
