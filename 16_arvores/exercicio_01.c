/*
 * Considerando estruturas de árvores binárias que armazenam valores inteiros, imple-
 * mente uma função que, dada uma árvore, retorne a quantidade de nós que guardam
 * números pares. Essa função deve obedecer ao protótipo:
 *
 * 		int pares (Arv* a);
 */

static int no_pares(ArvNo * r)
{
	if (!r) {
		return 0;
	}
	return !(r->info % 2) + no_pares(r->esq) + no_pares(r->dir);
}

int pares(Arv * a)
{
	return no_pares(a->raiz);
}
