#include <stdio.h>
#include <stdlib.h>
#include "strdin.h"

StrDin *le_texto(char *arquivo)
{
	char buf[121];
	FILE *f = fopen(arquivo, "rt");
	StrDin *sd = sd_criavazia();

	if (!f) {
		free(sd);
		perror("");
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, sizeof(buf), f)) {
		sd_concatena(sd, buf);
	}
	fclose(f);
	return sd;
}

int main(void)
{
	StrDin *sd = le_texto("strdin.c");
	sd_redimensiona(sd);
	printf("%s", sd_acessa(sd));
	sd_libera(sd);
	return 0;
}
