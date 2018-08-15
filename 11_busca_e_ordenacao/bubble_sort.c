#include <stdio.h>

void bubble_sort(int n, int *vet)
{
	for (int i = n - 1; i > 0; i--) {
		int trocou = 0;
		for (int j = 0; j < i; j++) {
			if (vet[j] > vet[j + 1]) {
				trocou = 1;
				int t = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = t;
			}
		}
		if (!trocou) {
			break;
		}
	}
}

void bubble_sort_rec(int n, int *vet)
{
	int trocou = 0;
	for (int i = 0; i < n; i++) {
		if (vet[i] > vet[i + 1]) {
			int t = vet[i];
			vet[i] = vet[i + 1];
			vet[i + 1] = t;
			trocou = 1;
		}
	}
	if (trocou) {
		bubble_sort(n - 1, vet);
	}
}

static void *acessa(void *v, int i, int tam)
{
	char *p = (char *)v;
	return (void *)(p + i * tam);
}

static void troca(void *v1, void *v2, int tam)
{
	char *p1 = (char *)v1;
	char *p2 = (char *)v2;
	for (int i = 0; i < tam; i++) {
		char t = p1[i];
		p1[i] = p2[i];
		p2[i] = t;
	}
}

void bubble_sort_gen(int n, void *v, int tam, int (*cmp) (void *v1, void *v2))
{
	for (int i = n - 1; i > 0; i--) {
		int trocou = 0;
		for (int j = 0; j < i; j++) {
			void *v1 = acessa(v, j, tam);
			void *v2 = acessa(v, j + 1, tam);
			if (cmp(v1, v2) > 0) {
				troca(v1, v2, tam);
				trocou = 1;
			}
		}
		if (!trocou) {
			return;
		}
	}
}

static int compara_int(void *v1, void *v2)
{
	int *p1 = (int *)v1;
	int *p2 = (int *)v2;
	return *p1 - *p2;
}

static int compara_float(void *v1, void *v2)
{
	float *p1 = (float *)v1;
	float *p2 = (float *)v2;
	return *p1 - *p2;
}

int main(void)
{
	int vet[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	bubble_sort_gen(10, vet, sizeof(int), compara_int);
	for (int i = 0; i < 10; i++) {
		printf("%d ", vet[i]);
	}
	puts("");
	return 0;
}
