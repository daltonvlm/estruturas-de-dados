#include <stdio.h>
#include <stdlib.h>

static void *acessa(void *v, int i, size_t tam)
{
	return ((char *)v) + (i * tam);
}

static void troca(void *v1, void *v2, size_t tam)
{
	char *p1 = (char *)v1;
	char *p2 = (char *)v2;
	for (int i = 0; i < tam; i++) {
		char tmp = p1[i];
		p1[i] = p2[i];
		p2[i] = tmp;
	}
}

int binary_search(int n, int *vet, size_t tam,
		  int (*cmp) (const void *, const void *), void *e)
{
	int ini = 0;
	int fim = n - 1;
	while (ini <= fim) {
		int med = (ini + fim) / 2;
		void *p = acessa(vet, med, tam);
		int c = cmp(e, p);
		if (c < 0)
			fim = med - 1;
		else if (c > 0)
			ini = med + 1;
		else
			return med;
	}
	return -1;
}

int binary_search_rec(int n, int *vet, size_t tam,
		      int (*cmp) (const void *, const void *), void *e)
{
	if (0 == n)
		return -1;
	int med = n / 2;
	void *p = acessa(vet, med, tam);
	int c = cmp(e, p);
	if (c < 0) {
		return binary_search_rec(med, vet, tam, cmp, e);
	}
	if (c > 0) {
		p = acessa(vet, med + 1, tam);
		int r = binary_search_rec(n - med - 1, p, tam, cmp, e);
		return -1 == r ? -1 : med + r + 1;
	}
	return med;
}

void bubble_sort(int n, void *vet, size_t tam,
		 int (*cmp) (const void *, const void *))
{
	for (int i = n - 1; i > 0; i--) {
		int trocou = 0;
		for (int j = 0; j < i; j++) {
			void *p1 = acessa(vet, j, tam);
			void *p2 = acessa(vet, j + 1, tam);
			if (cmp(p1, p2) > 0) {
				troca(p1, p2, tam);
				trocou = 1;
			}
		}
		if (!trocou)
			return;
	}
}

void bubble_sort_rec(int n, int *vet, size_t tam,
		     int (*cmp) (const void *, const void *))
{
	int trocou = 0;
	for (int i = 0; i < n - 1; i++) {
		void *p1 = acessa(vet, i, tam);
		void *p2 = acessa(vet, i + 1, tam);
		if (cmp(p1, p2) > 0) {
			troca(p1, p2, tam);
			trocou = 1;
		}
	}
	if (trocou)
		bubble_sort_rec(n - 1, vet, tam, cmp);
}

void quick_sort(void *v, int n, size_t tam,
		int (*cmp) (const void *v1, const void *v2))
{
	if (n <= 1)
		return;

	int a = 1;
	int b = n - 1;

	void *pa = acessa(v, a, tam);
	void *pb = acessa(v, b, tam);

	do {
		while (a < n && cmp(pa, v) <= 0) {
			a++;
			pa = acessa(v, a, tam);
		}
		while (cmp(pb, v) > 0) {
			b--;
			pb = acessa(v, b, tam);
		}
		if (a < b) {
			troca(pa, pb, tam);
		}
	} while (a <= b);

	troca(v, pb, tam);
	quick_sort(v, b, tam, cmp);
	quick_sort(pa, n - a, tam, cmp);
}
