#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "heap.h"

#define N 100

int main(void)
{
	Heap *h;
	float v[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		v[i] = (float)((double)rand() / RAND_MAX);
	}
	h = heap_constroi(N, v);
	assert(heap_verifica(h));
	heap_libera(h);
	return 0;
}
