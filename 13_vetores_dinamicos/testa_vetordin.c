#include <stdio.h>
#include <stdlib.h>
#include "vetordin.h"

VetorDin *le_valores(char *arquivo)
{
	float x;
	FILE *f = fopen(arquivo, "rt");
	VetorDin *vd = vd_cria();

	if (!f) {
		vd_libera(vd);
		return NULL;
	}
	while (1 == fscanf(f, "%f", &x)) {
		vd_insere(vd, x);
	}
	fclose(f);
	return vd;
}

int main(void)
{
	VetorDin *vd = le_valores("numeros.txt");
	int tam;

	if (!vd) {
		perror("");
		exit(EXIT_FAILURE);
	}
	tam = vd_tam(vd);
	for (int i = 0; i < tam; i++) {
		printf("%f\n", vd_acessa(vd, i));
	}
	free(vd);
	return 0;
}
