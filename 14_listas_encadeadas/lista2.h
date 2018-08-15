#ifndef LISTA2_H
#define LISTA2_H

typedef struct lista2 Lista2;
typedef struct no No;
struct no {
	int info;
	No *ant;
	No *prox;
};

Lista2 *lst2_cria(void);
void lst2_libera(Lista2 * lst);
void lst2_insere_inicio(Lista2 * lst, int v);
void lst2_insere_final(Lista2 * lst, int v);
No *lst2_busca(Lista2 * lst, int v);
void lst2_retira(Lista2 * lst, int v);
int lst2_vazia(Lista2 * lst);

#endif
