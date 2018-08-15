#include <stdio.h>
#include <stdlib.h>
#include "vetordin.h"

VetorDin *le_valores(char *arquivo)
{
	char buf[121];
	FILE *f = fopen(arquivo, "rt");
	VetorDin *vd = vd_cria();

	if (!f) {
		free(vd);
		return NULL;
	}

	while (fgets(buf, sizeof(buf), f)) {
		float x;
		if (sscanf(buf, "%f", &x) == 1) {
			vd_insere(vd, x);
		}
	}
	fclose(f);
	return vd;
}

int main(void)
{
	VetorDin *vd = le_valores("numeros.txt");

	if (!vd) {
		perror("Erro");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < vd_tam(vd); i++) {
		printf("%f\n", vd_acessa(vd, i));
	}

	free(vd);
	return 0;
}
