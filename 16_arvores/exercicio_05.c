/*
 * Implemente uma função que crie uma cópia de uma árvore binária. Essa função
 * deve obedecer ao protótipo:
 *
 * 		Arv* copia (Arv* a);
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

static void arvno_copia(ArvNo ** p, ArvNo * r)
{
	*p = NULL;
	if (r) {
		*p = (ArvNo *) aloca(sizeof(ArvNo));
		(*p)->info = r->info;
		arvno_copia(&(*p)->esq, r->esq);
		arvno_copia(&(*p)->dir, r->dir);
	}
}

Arv *copia(Arv * a)
{
	Arv *cp = (Arv *) aloca(sizeof(Arv));
	arvno_copia(&cp->raiz, a->raiz);
	return cp;
}
