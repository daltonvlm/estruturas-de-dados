/*
 * Considerando estruturas de árvores com número variável de filhos, implemente uma
 * função que retorne a quantidade de nós que possuem apenas um filho. Essa função
 * deve obedecer ao protótipo:
 *
 * 		int um_filho (Arvn* a);
 */

static int arvnno_um_filho(ArvnNo * r)
{
	int n = r->prim && !r->prim->prox;
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		n += arvnno_um_filho(p);
	}
	return n;
}

int um_filho(Arvn * a)
{
	return a->raiz ? arvnno_um_filho(a->raiz) : 0;
}
