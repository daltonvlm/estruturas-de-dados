#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "heap.h"

#define N 100

typedef struct float_t Float;
struct float_t {
	float x;
};

static int cmp(const void *v1, const void *v2)
{
	Float *f1 = (Float *) v1;
	Float *f2 = (Float *) v2;

	if (*f1 < *f2) {
		return -1;
	}
	if (*f1 > *f2) {
		return 1;
	}
	return 0;
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

int main(void)
{
	Heap *h = heap_cria(cmp);
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		Float *f = (Float *) aloca(sizeof(Float));
		f->x = (float)((double)rand() / RAND_MAX);
		heap_insere(h, f);
		assert(heap_verifica(h));
	}
	while (!heap_vazia(h)) {
		Float *f = heap_retira(h);
		printf("%.5f\n", f->x);
		assert(heap_verifica(h));
		free(f);
	}
	heap_libera(h, NULL);
	return 0;
}
