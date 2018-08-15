#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "vetbit.h"

#define NMAX 100

static VetBit *cria_aleatorio(void)
{
	int nsets = rand() % NMAX;
	VetBit *s = vb_cria(NMAX);

	for (int i = 0; i < nsets; i++) {
		vb_liga(s, rand() % NMAX);
	}
	return s;
}

static void retira_todos(VetBit * s)
{
	for (int i = 0; i < NMAX; i++) {
		if (vb_acessa(s, i)) {
			vb_desliga(s, i);
		}
	}
	assert(vb_vazio(s));
}

/* Verifica regras comutativas */
static void prop_comutativas(void)
{
	VetBit *a = cria_aleatorio();
	VetBit *b = cria_aleatorio();
	VetBit *u1 = vb_uniao(a, b);
	VetBit *u2 = vb_uniao(b, a);
	VetBit *i1 = vb_inter(a, b);
	VetBit *i2 = vb_inter(b, a);

	assert(vb_igual(u1, u2));
	assert(vb_igual(i1, i2));

	vb_libera(a);
	vb_libera(b);
	vb_libera(u1);
	vb_libera(u2);
	vb_libera(i1);
	vb_libera(i2);
}

/* Verifica complemento da interseção: ~(a I b) = ~a U ~b */
static void prop_comp_inter(void)
{
	VetBit *a = cria_aleatorio();
	VetBit *b = cria_aleatorio();
	VetBit *i = vb_inter(a, b);
	VetBit *ci = vb_compl(i);
	VetBit *ca = vb_compl(a);
	VetBit *cb = vb_compl(b);
	VetBit *uc = vb_uniao(ca, cb);

	assert(vb_igual(ci, uc));

	vb_libera(a);
	vb_libera(b);
	vb_libera(i);
	vb_libera(ci);
	vb_libera(ca);
	vb_libera(cb);
	vb_libera(uc);
}

/* Verifica complemento da união: ~(a U b) = ~a I ~b */
static void prop_comp_uniao(void)
{
	VetBit *a = cria_aleatorio();
	VetBit *b = cria_aleatorio();
	VetBit *u = vb_uniao(a, b);
	VetBit *cu = vb_compl(u);
	VetBit *ca = vb_compl(a);
	VetBit *cb = vb_compl(b);
	VetBit *ic = vb_inter(ca, cb);

	assert(vb_igual(cu, ic));

	vb_libera(a);
	vb_libera(b);
	vb_libera(u);
	vb_libera(cu);
	vb_libera(ca);
	vb_libera(cb);
	vb_libera(ic);
}

/* Verifica que: a U (b \ a) = a U b */
static void prop_dif_1(void)
{
	VetBit *a = cria_aleatorio();
	VetBit *b = cria_aleatorio();
	VetBit *dif = vb_dif(b, a);
	VetBit *u1 = vb_uniao(a, dif);
	VetBit *u2 = vb_uniao(a, b);

	assert(vb_igual(u1, u2));

	vb_libera(a);
	vb_libera(b);
	vb_libera(dif);
	vb_libera(u1);
	vb_libera(u2);
}

/* Verifica que: a I (b \ a) = 0 */
static void prop_dif_2(void)
{
	VetBit *a = cria_aleatorio();
	VetBit *b = cria_aleatorio();
	VetBit *dif = vb_dif(b, a);
	VetBit *i = vb_inter(a, dif);
	VetBit *vazio = vb_cria(NMAX);

	assert(vb_igual(i, vazio));

	vb_libera(a);
	vb_libera(b);
	vb_libera(dif);
	vb_libera(i);
	vb_libera(vazio);
}

/* Verifica que: a \ (b U c) = (a \ b) I (a \ c) */
static void prop_dif_3(void)
{
	VetBit *a = cria_aleatorio();
	VetBit *b = cria_aleatorio();
	VetBit *c = cria_aleatorio();

	VetBit *u = vb_uniao(b, c);
	VetBit *dif1 = vb_dif(a, u);

	VetBit *dif2 = vb_dif(a, b);
	VetBit *dif3 = vb_dif(a, c);
	VetBit *i = vb_inter(dif2, dif3);

	assert(vb_igual(dif1, i));

	vb_libera(a);
	vb_libera(b);
	vb_libera(c);
	vb_libera(u);
	vb_libera(dif1);
	vb_libera(dif2);
	vb_libera(dif3);
	vb_libera(i);
}

/* Verifica que: a \ (b I c) = (a \ b) U (a \ c) */
static void prop_dif_4(void)
{
	VetBit *a = cria_aleatorio();
	VetBit *b = cria_aleatorio();
	VetBit *c = cria_aleatorio();

	VetBit *i = vb_inter(b, c);
	VetBit *dif1 = vb_dif(a, i);

	VetBit *dif2 = vb_dif(a, b);
	VetBit *dif3 = vb_dif(a, c);
	VetBit *u = vb_uniao(dif2, dif3);

	assert(vb_igual(dif1, u));

	vb_libera(a);
	vb_libera(b);
	vb_libera(c);
	vb_libera(i);
	vb_libera(dif1);
	vb_libera(dif2);
	vb_libera(dif3);
	vb_libera(u);
}

int main(void)
{
	srand(time(NULL));
	for (int k = 0; k < 10; k++) {
		VetBit *s = cria_aleatorio();
		retira_todos(s);
		vb_libera(s);
		prop_comutativas();
		prop_comp_inter();
		prop_comp_uniao();
		prop_dif_1();
		prop_dif_2();
		prop_dif_3();
		prop_dif_4();
	}

	puts("ok");
	return 0;
}
