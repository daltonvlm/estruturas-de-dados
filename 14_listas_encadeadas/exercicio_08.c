/*
 * Implemente uma função que receba como parâmetro uma lista encadeada e inverta o
 * encadeamento de seus nós. Após a execução dessa função, cada nó da lista vai estar
 * apontando para o nó que originalmente era seu antecessor, e o último nó da lista
 * passará a ser o primeiro nó da lista invertida, conforme ilustrado na Figura 14.12.
 *
 * (Figura no livro)
 *
 * Essa função deve obedecer ao protótipo:
 *
 * 		void inverte (Lista* l);
 */

void inverte(Lista * l)
{
	ListaNo *ant = NULL;
	for (ListaNo * p = l->prim; p; p = l->prim) {
		l->prim = p->prox;
		p->prox = ant;
		ant = p;
	}
	l->prim = ant;
}
