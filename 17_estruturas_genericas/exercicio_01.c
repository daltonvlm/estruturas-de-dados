/*
 * Crie um TAD para representar vetor dinâmico genérico capaz de armazenar pon-
 * teiro para qualquer tipo. A interface deste TAD deve serguir o arquivo "vetgen.h":
 *
 * 		// Vetor genérico que armazena void
 * 		typedef struct vetorgen VetorGen;
 *
 *		// cria vetor vazio
 *		VetorGen* vgen_cria (void);
 *
 *		// insere novo elemento no final do vetor
 *		void vgen_insere (VetorGen* v, void* p);
 *
 *		// retorna o número de elementos do vetor
 *		int vgen_tam (VetorGen* v);
 *
 *		// retorna a informação associada ao elemento de índice i
 *		void* vgen_acessa (VetorGen* v, int i);
 *
 *		// percorre os elementos do vetor chamando a callback
 *		int vgen_percorre (VetorGen* v,
 *						   int (*cb) (void* info, void* dado),
 *						   void* dado
 *						   );
 *
 *		// libera a memória do vetor, chamando a callback
 *		void vgen_libera (VetorGen* v, void (*cb) (void*));
 */

#include <stdio.h>
#include <stdlib.h>
#include "vetgen.h"

int soma(void *info, void *dado)
{
	int *p = (int *)info;
	int *q = (int *)dado;

	*q += *p;
	return 0;
}

int main(void)
{
	VetorGen *vg = vgen_cria();
	int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < 10; i++)
		vgen_insere(vg, nums + i);

	printf("n: %d\n", vgen_tam(vg));

	for (int i = 0; i < 10; i++) {
		int *n = (int *)vgen_acessa(vg, i);
		printf("%d ", *n);
	}
	puts("");

	int s = 0;
	vgen_percorre(vg, soma, &s);
	printf("soma: %d\n", s);

	vgen_libera(vg, NULL);
	return 0;
}
