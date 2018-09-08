/*
 * Considerando listas de valores inteiros, implemente uma função que receba como
 * parâmetro uma lista encadeada e um valor inteiro x e divida a lista em duas, de
 * tal forma que a segunda lista, criada dentro da função, comece no primeiro nó logo
 * após a primeira ocorrência de x na lista original. A função deve ter como valor
 * de retorno a lista criada, mesmo que ela seja vazia. A Figura 14.10 ilustra este
 * procedimento.
 *
 * Essa função deve obedecer ao protótipo:
 * 		
 * 		Lista* separa (Lista* l, int x);
 *
 * (Figura no livro)
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

Lista *separa(Lista * l, int x)
{
	ListaNo *p = l->prim;
	Lista *l2 = (Lista *) aloca(sizeof(Lista));
	l2->prim = NULL;

	while (p && p->info != x) {
		p = p->prox;
	}
	if (p) {
		l2->prim = p->prox;
		p->prox = NULL;
	}
	return l2;
}
