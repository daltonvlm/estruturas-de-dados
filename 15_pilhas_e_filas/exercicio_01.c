/*
 * Considerando a existência de um tipo abstrato Pilha de números reais, cuja interface
 * está definida no arquivo "pilha.h" da seguinte forma:
 *
 * 	typedef struct pilha Pilha;
 * 	Pilha* pilha_cria (void);
 * 	void pilha_push (Pilha* p, float v);
 * 	float pilha_pop (Pilha* p);
 * 	int pilha_vazia(Pilha* p);
 * 	void pilha_libera(Pilha* p);
 *
 * Sem conhecer a representação interna desse tipo abstrato e usando apenas as fun-
 * ções declaradas no arquivo de interface, pede-se:
 *
 * 	(a)	Implemente uma função que receba uma pilha como parâmetro e retorne o
 * 		valor armazenado em seu topo, restaurando o conteúdo da pilha. Essa função
 * 		deve obedecer ao protótipo:
 *
 * 		float topo (Pilha* p);
 *
 * 	(b)	Implemente uma função que receba duas pilhas, p1 e p2, e passe todos os
 * 		elementos da pilha p2 para o topo da pilha p1. A Figura 15.6 ilustra essa
 * 		concatenação de pilhas. Note que, ao final dessa função, a pilha p2 vai estar
 * 		vazia e a pilha p1 conterá todos os elementos das duas pilhas.
 *
 * 		(Figura no livro)
 *
 * 		Essa função deve obedecer ao protótipo:
 *
 * 			void concatena_pilhas (Pilha* p1, Pilha* p2);
 *
 * 		Implemente esta função de duas formas distintas: (i) usando uma função
 * 		recursiva; (ii) usando uma terceira pilha auxiliar.
 *
 * 	(c)	Implemente uma função que receba uma pilha como parâmetro e retorne como
 * 		resultado uma cópia dessa pilha. Essa função deve obedecer ao protótipo:
 *
 * 			Pilha* copia_pilha (Pilha* p);
 *
 * 		Ao final da função copia_pilha, a pilha p recebida como parâmetro deve ter
 * 		seu conteúdo original. Implemente duas versões desta função: usando recursão
 * 		e usando uma pilha auxiliar.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

float topo(Pilha * p)
{
	float v = pilha_pop(p);
	pilha_push(p, v);
	return v;
}

void concatena_pilhas(Pilha * p1, Pilha * p2)
{
	Pilha *t = pilha_cria();
	while (!pilha_vazia(p2)) {
		pilha_push(t, pilha_pop(p2));
	}
	while (!pilha_vazia(t)) {
		pilha_push(p1, pilha_pop(t));
	}
	free(t);
}

void concatena_pilhas_rec(Pilha * p1, Pilha * p2)
{
	if (!pilha_vazia(p2)) {
		float v = pilha_pop(p2);
		concatena_pilhas_rec(p1, p2);
		pilha_push(p1, v);
	}
}

Pilha *copia_pilha(Pilha * p)
{
	Pilha *t = pilha_cria();
	Pilha *cp = pilha_cria();
	while (!pilha_vazia(p)) {
		pilha_push(t, pilha_pop(p));
	}
	while (!pilha_vazia(t)) {
		pilha_push(p, pilha_pop(t));
		pilha_push(cp, topo(p));
	}
	free(t);
	return cp;
}

static void copia(Pilha * cp, Pilha * orig)
{
	if (!pilha_vazia(orig)) {
		float v = pilha_pop(orig);
		copia(cp, orig);
		pilha_push(orig, v);
		pilha_push(cp, v);
	}
}

Pilha *copia_pilha_rec(Pilha * p)
{
	Pilha *cp = pilha_cria();
	copia(cp, p);
	return cp;
}

int main(void)
{
	Pilha *p1 = pilha_cria();
	Pilha *p2;
	for (int i = 0; i < 10; i++) {
		pilha_push(p1, i);
	}
	puts("p1:");
	pilha_imprime(p1);
	p2 = copia_pilha_rec(p1);
	puts("p2:");
	pilha_imprime(p2);
	pilha_libera(p1);
	pilha_libera(p2);
	return 0;
}
