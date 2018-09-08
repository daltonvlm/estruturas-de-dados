/*
 * Considerando estruturas de árvores com número variável de filhos que armazenam
 * valores inteiros, implemente uma função que, dada uma árvore, retorne a quanti-
 * dade de nós que guardam números pares. Essa função deve obedecer ao protótipo:
 *
 * 		int pares (Arvn* a);
 */

static int arvnno_pares(ArvnNo * r)
{
	int pares = 0;
	if (!(r->info % 2)) {
		pares++;
	}
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		pares += arvnno_pares(p);
	}
	return pares;
}

int pares(Arvn * a)
{
	return a->raiz ? arvnno_pares(a->raiz) : 0;
}
