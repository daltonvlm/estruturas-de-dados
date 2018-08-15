#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetbit.h"

#define W (sizeof(word)*8)

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef unsigned char word;

struct vetbit {
	int n;
	word *v;
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

VetBit *vb_cria(int nmax)
{
	VetBit *s = (VetBit *) aloca(sizeof(VetBit));
	s->n = (nmax - 1) / W + 1;
	s->v = (word *) aloca(s->n * sizeof(word));
	vb_limpa(s);
	return s;
}

void vb_libera(VetBit * s)
{
	free(s->v);
	free(s);
}

static void realoca(VetBit * s, int n)
{
	s->v = (word *) realloc(s->v, n * sizeof(word));
	if (!s->v) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	memset(s->v + s->n, 0, (n - s->n) * sizeof(word));
	s->n = n;
}

void vb_liga(VetBit * s, int i)
{
	if (i < 0) {
		return;
	}
	int n = i / W;
	if (n >= s->n) {
		realoca(s, n + 1);
	}
	s->v[i / W] |= 1 << (i % W);
}

void vb_desliga(VetBit * s, int i)
{
	if (i < 0 || (i / W >= s->n)) {
		return;
	}
	s->v[i / W] &= ~(1 << (i % W));
}

int vb_acessa(VetBit * s, int i)
{
	if (i < 0 || (i / W >= s->n)) {
		return 0;
	}
	return (s->v[i / W] & (1 << (i % W))) >> (i % W);
}

int vb_vazio(VetBit * s)
{
	for (int i = 0; i < s->n; i++) {
		if (s->v[i]) {
			return 0;
		}
	}
	return 1;
}

void vb_limpa(VetBit * s)
{
	memset(s->v, 0, s->n * sizeof(word));
}

VetBit *vb_uniao(VetBit * a, VetBit * b)
{
	int i;
	VetBit *s = vb_cria(max(a->n, b->n) * W);

	for (i = 0; i < a->n && i < b->n; i++) {
		s->v[i] = a->v[i] | b->v[i];
	}
	for (; i < a->n; i++) {
		s->v[i] = a->v[i];
	}
	for (; i < b->n; i++) {
		s->v[i] = b->v[i];
	}
	return s;
}

VetBit *vb_inter(VetBit * a, VetBit * b)
{
	/*
	VetBit *s = NULL;
	if (a->n == b->n) {
		s = vb_cria(a->n * W);
		for (int i = 0; i < s->n; i++) {
			s->v[i] = a->v[i] & b->v[i];
		}
	}
	return s;
	*/
	int i;
	VetBit*s=vb_cria(min(a->n,b->n)*W);

	for(i=0;i<a->n&&i<b->n;i++){
		s->v[i]=a->v[i]&b->v[i];
	}
	return s;
}

VetBit *vb_compl(VetBit * s)
{
	VetBit *c = vb_cria(s->n * W);
	for (int i = 0; i < c->n; i++) {
		c->v[i] = ~s->v[i];
	}
	return c;
}

int vb_igual(VetBit * a, VetBit * b)
{
	if (a->n != b->n) {
		return 0;
	}
	for (int i = 0; i < a->n; i++) {
		if (a->v[i] != b->v[i]) {
			return 0;
		}
	}
	return 1;
}

VetBit *vb_dif(VetBit * a, VetBit * b)
{
	VetBit *d = NULL;
	if (a->n == b->n) {
		d = vb_cria(a->n * W);
		d->n = a->n;
		for (int i = 0; i < d->n; i++) {
			d->v[i] = a->v[i] & ~b->v[i];
		}
	}
	return d;
}
