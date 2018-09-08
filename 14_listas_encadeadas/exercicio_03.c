/*
 * Implemente uma função que retorne o último valor de uma lista encadeada de
 * inteiros. Essa função deve obedecer ao protótipo:
 *
 * 		int ultimo (Lista *l);
 */

int ultimo(Lista * l)
{
	ListaNo *p = l->prim;
	if (p) {
		while (p->prox) {
			p = p->prox;
		}
		return p->info;
	}
	fprintf(stderr, "Erro: lista vazia\n");
	exit(EXIT_FAILURE);
}
