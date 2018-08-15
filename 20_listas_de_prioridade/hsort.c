#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define N 100

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

static void troca(float *v, int i, int j)
{
	float tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

static void desce(int n, float *v, int i)
{
	int c = esq(i);
	while (c < n) {
		int c2 = dir(i);
		if (c2 < n && v[c2] > v[c]) {
			c = c2;
		}
		if (v[c] <= v[i]) {
			break;
		}
		troca(v, i, c);
		i = c;
		c = esq(i);
	}
}

void hsort(int n, float *v)
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		desce(n, v, i);
	}
	while (n) {
		troca(v, 0, --n);
		desce(n, v, 0);
	}
}

int main(void)
{
	float v[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		v[i] = (float)((double)rand() / RAND_MAX);
	}
	hsort(N, v);
	for (int i = 1; i < N; i++) {
		assert(v[i] > v[i - 1]);
	}
	puts("ok");
	return 0;
}
