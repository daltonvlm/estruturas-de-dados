/*
 * Implemente uma função que construa uma nova lista, intercalando os nós de outras
 * duas listas passadas como parâmetros. Essa função deve retornar a nova lista
 * resultante, criada dentro da função, conforme ilustrado na Figura 14.11.
 *
 * (Figura no livro)
 *
 * Ao final da função, as listas originais devem ficar vazias e ser liberadas. Se uma
 * lista tiver mais elementos que a outra, os elementos excedentes são transferidos na
 * mesma ordem para a nova lista. Essa função deve obedecer ao protótipo:
 *
 * 		Lista* merge (Lista* l1, Lista* l2);
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

Lista *merge(Lista * l1, Lista * l2)
{
	Lista *merge = (Lista *) aloca(sizeof(Lista));
	ListaNo **p = &merge->prim;
	while (l1->prim && l2->prim) {
		ListaNo *t1 = l1->prim;
		ListaNo *t2 = l2->prim;

		l1->prim = t1->prox;
		l2->prim = t2->prox;

		t1->prox = t2;
		*p = t1;
		p = &t2->prox;
	}
	*p = l1->prim ? l1->prim : l2->prim;
	l1->prim = NULL;
	l2->prim = NULL;
	free(l1);
	free(l2);
	return merge;
}
