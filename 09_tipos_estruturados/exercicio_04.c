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
	return sqrt(powf(p->x - q->x, 2) + powf(p->y - q->y, 2));
}

int intersecao(Circulo * a, Circulo * b)
{
	float d = distancia(&a->c, &b->c);
	return d <= a->r + b->r;
}

float comprimento(int n, Ponto * v)
{
	float c = 0;
	for (int i = 0; i < n - 1; i++) {
		c += distancia(v + i, v + i + 1);
	}
	return c;
}

int main(void)
{
	int c;
	Circulo c1 = { {0, 0}, 2 };
	Circulo c2 = { {3, .0}, 2 };
	Ponto v[] = { {0, 1}, {1, 1}, {2, 1}, {3, 1} };
	printf("Intersecao: %d\n", intersecao(&c1, &c2));
	c = comprimento(4, v);
	printf("Comprimento: %d\n", c);
	return 0;
}
