/*
 * Implemente uma função que retorne o somatório dos valores entre x e y (conside-
 * rando x > y) armazenados numa árvore binária de busca de valores inteiros. Essa
 * função deve obedecer ao protótipo:
 *
 * 		int soma_xy (Arv* a,int x, int y);
 */

static int arvno_soma_xy(ArvNo * r, int x, int y)
{
	if (r) {
		int n = r->info >= y && r->info <= x ? r->info : 0;
		if (r->info <= x) {
			n += arvno_soma_xy(r->dir, x, y);
		}
		if (r->info >= y) {
			n += arvno_soma_xy(r->esq, x, y);
		}
		return n;
	}
	return 0;
}

int soma_xy(Arv * a, int x, int y)
{
	return arvno_soma_xy(a->raiz, x, y);
}
