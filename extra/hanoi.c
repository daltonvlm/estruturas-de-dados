#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct {
	int topo;
	int v[N];
} Pilha;

static Pilha orig = { N - 1, -1 };
static Pilha dest = { -1, -1 };
static Pilha trab = { -1, -1 };

static void imprime(Pilha * p)
{
	for (int i = 0; i <= p->topo; i++) {
		printf("%d ", p->v[i]);
	}
	puts("");
}

static void imprime_pilhas(void)
{
	static int passo = 0;
	printf("passo: %d\n", passo++);
	printf("original: ");
	imprime(&orig);
	printf("destino: ");
	imprime(&dest);
	printf("trabalho: ");
	imprime(&trab);
	getchar();
}

void hanoi(int n, Pilha * o, Pilha * d, Pilha * t)
{
	if (n) {
		hanoi(n - 1, o, t, d);
		d->v[++d->topo] = o->v[o->topo--];
		imprime_pilhas();
		hanoi(n - 1, t, d, o);
	}
}

int main(void)
{
	for (int i = 0; i < N; i++) {
		orig.v[i] = N - i;
	}
	imprime_pilhas();
	hanoi(N, &orig, &dest, &trab);
	return 0;
}
