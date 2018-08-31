#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strdin.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

struct strdin {
	int nmax;
	char *v;
};

StrDin *sd_criavazia(void)
{
	return sd_criacopia("");
}

StrDin *sd_criacopia(const char *s)
{
	StrDin *sd = (StrDin *) malloc(sizeof(StrDin));
	if (!sd) {
		perror("");
		exit(EXIT_FAILURE);
	}
	sd->nmax = 0;
	sd->v = NULL;
	sd_atribui(sd, s);
	return sd;
}

static void realoca(StrDin * sd, int n)
{
	if (n >= sd->nmax) {
		sd->nmax = max(n, 2 * sd->nmax);
	} else if (n < sd->nmax / 2) {
		sd->nmax /= 2;
	}
	sd->v = (char *)realloc(sd->v, sd->nmax + 1);
	if (!sd->v) {
		perror("");
		exit(EXIT_FAILURE);
	}
}

void sd_atribui(StrDin * sd, const char *s)
{
	realoca(sd, strlen(s));
	strcpy(sd->v, s);
}

void sd_concatena(StrDin * sd, const char *s)
{
	realoca(sd, strlen(sd->v) + strlen(s));
	strcat(sd->v, s);
}

const char *sd_acessa(StrDin * sd)
{
	return sd->v;
}

void sd_libera(StrDin * sd)
{
	free(sd->v);
	free(sd);
}

void sd_redimensiona(StrDin * sd)
{
	sd->nmax = strlen(sd->v);
	sd->v = (char *)realloc(sd->v, sd->nmax + 1);
	if (!sd->v) {
		perror("");
		exit(EXIT_FAILURE);
	}
}
