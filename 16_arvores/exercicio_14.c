/*
 * Implemente uma função que crie uma cópia de uma árvore. Essa função deve
 * obedecer ao protótipo:
 *
 * 		Arvn* copia (Arvn* a);
 */

static ArvnNo *arvnno_copia(ArvnNo * r)
{
	ArvnNo *novo = NULL;
	if (r) {
		novo = (ArvnNo *) aloca(sizeof(ArvnNo));
		novo->info = r->info;
		novo->prim = arvnno_copia(r->prim);
		novo->prox = arvnno_copia(r->prox);
	}
	return novo;
}

Arvn *copia(Arvn * a)
{
	Arvn *cp = (Arvn *) aloca(sizeof(Arvn));
	cp->raiz = arvnno_copia(a->raiz);
	return cp;
}
