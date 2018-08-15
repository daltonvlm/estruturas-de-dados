#include <stdio.h>
#include <stdlib.h>

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

static void *acessa(void *v, size_t size, int i)
{
	return ((char *)v) + i * size;
}

static void troca(void *v1, void *v2, size_t size)
{
	{
		char *p1 = (char *)v1;
		char *p2 = (char *)v2;
		for (size_t i = 0; i < size; i++) {
			char tmp = p1[i];
			p1[i] = p2[i];
			p2[i] = tmp;
		}
	}
}

static void desce(void *v, size_t n, size_t size, int i,
		  int (*cmp) (const void *, const void *))
{
	size_t c = esq(i);
	while (c < n) {
		size_t c2 = dir(i);
		void *pc = acessa(v, size, c);
		void *pc2 = acessa(v, size, c2);
		void *pi = acessa(v, size, i);

		if (c2 < n && cmp(pc2, pc) > 0) {
			pc = pc2;
		}
		if (cmp(pc, pi) <= 0) {
			break;
		}
		troca(pi, pc, size);
		i = c;
		c = esq(i);
	}
}

void hsort(void *v, size_t n, size_t size,
	   int (*cmp) (const void *, const void *))
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		desce(v, n, size, i, cmp);
	}
	while (n) {
		void *fim = acessa(v, size, --n);
		troca(v, fim, size);
		desce(v, n, size, 0, cmp);
	}
}
