/*
 * Implemente uma função que retorne o nível do nó que contém a informação x numa
 * árvore binária de busca. Essa função deve obedecer ao protótipo:
 *
 * 		int nivel (Arv* a, int x);
 */

int nivel(Arv * a, int x)
{
	int n = 0;
	ArvNo *p = a->raiz;

	while (p && p->info != x) {
		if (x < p->info) {
			p = p->esq;
		} else {
			p = p->dir;
		}
		n++;
	}
	return p ? n : -1;
}

static int arvno_nivel_rec(ArvNo * r, int x)
{
	if (r) {
		if (x == r->info) {
			return 0;
		}
		int n = x < r->info ? arvno_nivel_rec(r->esq, x) :
		    arvno_nivel_rec(r->dir, x);
		return -1 == n ? n : n + 1;
	}
	return -1;
}

int nivel_rec(Arv * a, int x)
{
	return arvno_nivel_rec(a->raiz, x);
}
