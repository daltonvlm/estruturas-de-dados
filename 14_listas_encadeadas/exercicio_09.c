/*
 * Considerando listas que armazenam cadeias de caracteres, implemente as versões
 * iterativa e recursiva de uma função que cria uma cópia de uma lista encadeada.
 * Essa função deve obedecer ao protótipo:
 *
 * 		Lista* copia (Lista* l);
 */

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

static ListaNo *copia_no(ListaNo * p)
{
	ListaNo *cp = (ListaNo *) aloca(sizeof(ListaNo));
	strcp(cp->info, p->info);
	cp->prox = NULL;
	return cp;
}

Lista *copia(Lista * l)
{
	Lista *cp = (Lista *) aloca(sizeof(Lista));
	ListaNo **p = &cp->prim;
	for (ListaNo * q = l->prim; q; q = q->prox) {
		*p = copia_no(q);
		p = &(*p)->prox;
	}
	return cp;
}

static void copia_nos(ListaNo ** cp, ListaNo * orig)
{
	if (orig) {
		*cp = copia_no(orig);
		copia_nos(&(*cp)->prox, orig->prox);
	}
}

Lista *copia_rec(Lista * l)
{
	Lista *cp = (Lista *) aloca(sizeof(Lista));
	copia_nos(&cp->prim, l->prim);
	return cp;
}
