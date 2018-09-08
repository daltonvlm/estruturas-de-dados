/*
 * Defina estruturas para representar retângulos (dados a base e a altura) e círculos
 * (dado o raio), e implemente as funções a seguir:
 *
 * (a) Dado um círculo, crie e retorne o maior retângulo circunscrito de altura h;
 *     considere que h é menor do que o diâmetro do círculo:
 *
 *          Ret* ret_circunscrito (Circ* c, float h);
 *
 * (b) Dado um retângulo, crie e retorne o maior círculo interno ao retângulo:
 *
 *          Circ* circ_interno (Ret *r);
 */

#define min(a,b) ((a) < (b) ? (a) : (b))

typedef struct ret Ret;
struct ret {
	float h, b;
};

typedef struct circ Circ;
struct circ {
	float r;
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

Ret *ret_circunscrito(Circ * c, float h)
{
	Ret *r = (Ret *) aloca(sizeof(Ret));
	r->h = h;
	r->b = sqrt(4 * c->r * c->r + h * h);
	return r;
}

Circ *circ_interno(Ret * r)
{
	Circ *c = (Circ *) aloca(sizeof(Circ));
	c->r = min(r->b, r->h) / 2;
	return c;
}
