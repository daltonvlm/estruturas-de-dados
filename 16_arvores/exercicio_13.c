/*
 * Implemente uma função que compare se duas árvores são iguais. Essa função deve
 * obedecer ao protótipo:
 *
 * 		Arvn* igual (Arvn* a, Arvn* b);
 */

static int arvnno_igual(No * r, No * s)
{
	if (r && s) {
		return r->info == s->info &&
		    arvnno_igual(r->prim, s->prim) && arvnno_igual(r->prox, s->prox);
	}
	return r == s;
}

Arvn *igual(Arvn * a, Arvn * b)
{
	return arvnno_igual(a->raiz, b->raiz) ? a : NULL;
}
