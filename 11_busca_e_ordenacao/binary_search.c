#include <stdio.h>

int bsearch(int n, int *vet, int elem)
{
	int i = 0;
	int f = n - 1;
	while (i <= f) {
		int m = (i + f) / 2;
		if (vet[m] == elem) {
			return m;
		}
		if (vet[m] < elem) {
			i = m + 1;
		} else {
			f = m - 1;
		}
	}
	return -1;
}

int pertence_rec(int n, int *vet, int elem)
{
	if (!n) {
		return 0;
	}
	int m = n / 2;
	if (vet[m] < elem) {
		return pertence_rec(n - 1 - m, vet + m + 1, elem);
	}
	if (vet[m] > elem) {
		return pertence_rec(m, vet, elem);
	}
	return 1;
}

int bsearch_rec(int n, int *vet, int elem)
{
	if (!n) {
		return -1;
	}
	int m = n / 2;
	if (elem < vet[m]) {
		return bsearch_rec(m, vet, elem);
	}
	if (elem > vet[m]) {
		int r = bsearch(n - m - 1, vet + m + 1, elem);
		return r < 0 ? -1 : m + 1 + r;
	}
	return m;
}

int main(void)
{
	int vet[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	while (1) {
		int n;
		scanf("%d", &n);
		printf("%d\n", bsearch_rec(10, vet, n));
	}
	return 0;
}
