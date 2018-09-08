/*
 * Implemente uma função que retorne a quantidade de folhas de uma árvore com
 * número variável de filhos. Essa função deve obedecer ao protótipo:
 * 
 * 		int folhas (Arvn* a);
 */

static int arvnno_folhas(ArvnNo * r)
{
	int folhas = !r->prim;
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		folhas += arvnno_folhas(p);
	}
	return folhas;
}

int folhas(Arvn * a)
{
	return a->raiz ? arvnno_folhas(a->raiz) : 0;
}
