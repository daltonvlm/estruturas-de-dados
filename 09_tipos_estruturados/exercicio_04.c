/*
 * Considere as estruturas de Ponto e Circulo dadas a seguir:
 *
 *      typedef struct ponto Ponto;
 *      struct ponto {
 *          float x, y;
 *      };
 *
 *      typedef struct circulo Circulo;
 *      struct circulo {
 *          Ponto c;    // centro do círculo
 *          float r;    // raio
 *      };
 *
 * Pede-se:
 *
 *  (a) Implemente uma função que determine se dois círculos se interceptam. A
 *      função deve retornar 1, se houver interseção, ou 0, caso contrário, seguindo o
 *      protótipo:
 *      
 *          int intersecao (Circulo* a, Circulo* b);
 *
 *  (b) Considere um vetor de pontos que representa uma linha poligonal. Implemente
 *      uma função que calcule o comprimento da poligonal:
 *
 *          float comprimento (int n, Ponto* v);
 *
 *  (c) Escreva uma função main para testar as funções anteriores.
 */

#include <stdio.h>
#include <math.h>

typedef struct ponto Ponto;
struct ponto {
	float x, y;
};

typedef struct circulo Circulo;
struct circulo {
	Ponto c;
	float r;
};

static float distancia(Ponto * p, Ponto * q)
{
	return sqrt((p->x - q->x) * (p->x - q->x) +
		    (p->y - q->y) * (p->y - q->y));
}

int intersecao(Circulo * a, Circulo * b)
{
	return distancia(&a->c, &b->c) < a->r + b->r;
}

float comprimento(int n, Ponto * v)
{
	float d = .0f;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		d += distancia(&v[i], &v[j]);
	}
	return d;
}

int main(void)
{
	Circulo c1 = { {.0f, .0f}, 2 };
	Circulo c2 = { {3.f, .0f}, 2 };

	Ponto v[] = { {.0f, .0f}, {1.f, 1.f}, {2.f, 1.f}, {3.f, 0.f} };
	int c;

	printf("Intersecao: %d\n", intersecao(&c1, &c2));
	c = comprimento(4, v);
	printf("Comprimento: %d\n", c);
	return 0;
}
