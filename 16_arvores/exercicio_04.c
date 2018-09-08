/*
 * Implemente uma função que compare se duas árvores binárias são iguais. Essa
 * função deve obedecer ao protótipo:
 *
 * 		int igual (Arv* a, Arv* b);
 */

static int arvno_igual(ArvNo * p, ArvNo * q)
{
	if (p && q) {
		return p->info == q->info && arvno_igual(p->esq, q->esq)
		    && arvno_igual(p->dir, q->dir);
	}
	return p == q;
}

int igual(Arv * a, Arv * b)
{
	return arvno_igual(a->raiz, b->raiz);
}
