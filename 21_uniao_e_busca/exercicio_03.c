/*
 * Considere um conjunto de postes de luz localizados numa região plana. Qualquer
 * poste pode ser ligado com qualquer outro poste. Deseja-se criar uma conexão com
 * fios ligando todos os postes, sem redundância (sem criação de ciclos) e que gaste o
 * mínimo em fios para a conexão. A figura 21.8 ilustra uma solução do problema.
 * Faça um programa que leia as posições (x,y) dos postes, numerados de 0 a n-1,
 * e imprima os pares de postes que devem ser conecados de forma a usar a menor
 * quantidade de fios.
 * Este problema é conhecido como cálculo da árvore geradora mínima. Inicialmente,
 * qualquer par de postes representa uma conexão válida, onde a distância entre os
 * postes representa o custo em fios para efetuar a conexão. Queremos ligar totods os
 * postes com um custo mínimo. Um algoritmo para solucionar este problema consiste
 * simplesmente em processar as possíveis conexões em ordem crescente de custo: se
 * a conexão une dois pontos (postes) ainda não conectados (postes em partições
 * distintas) inclua a conxão na solução. Podemos implementar este procedimento
 * usando uma lista de prioridade para selecionar a próxima conexão de menor custo
 * e uma estrutra união-e-busca para controlar os pontos já conectados.
 *
 *  (Figura no livro).
 */

#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "aresta.h"
#include "vetorpontos.h"
#include "uniaobusca.h"
#include "heap.h"

static void libera_ponto(void*p){
	ponto_libera((Ponto*)p);
}

int main(void)
{
	int n= 0;
	VetorPontos *vp = vetorpontos_cria();
	UniaoBusca*ub;
	Heap*h;

	while (1) {
		float x, y;
		if (EOF == scanf("%f %f", &x, &y)) {
			break;
		}
		Ponto *p= ponto_cria(x, y, n++);
		vetorpontos_insere(vp, p);
	}

	ub=ub_cria(n);
	h=vetorpontos_cria_arestas(vp);

	while(!heap_vazia(h)){
		Ponto*p,*q;
		Aresta*a = (Aresta*)heap_retira(h);
		int x,y;

		aresta_pega_pontos(a,&p,&q);
		x=ub_busca(ub,ponto_pega_id(p));
		y=ub_busca(ub,ponto_pega_id(q));

		if(x!=y){
			ub_uniao(ub,x,y);
			aresta_imprime(a);
		}
		aresta_libera(a,NULL);
	}

	heap_libera(h,NULL);
	ub_libera(ub);
	vetorpontos_libera(vp,libera_ponto);
	return 0;
}
