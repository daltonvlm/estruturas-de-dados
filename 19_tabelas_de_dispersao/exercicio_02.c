/*
 * Implemente um código para fazer uma análise do desempenho de funções de busca,
 * comparando busca binária em vetor e busca em tabela de dispersão. O experimento
 * pode ser feito usando valores inteiros: buscar um valor inteiro em um vetor ordenado
 * versus buscar um valor inteiro em uma tabela de dispersão. Considerando que n
 * representa o número de valores inteiros, crie um vetor desta dimensão e uma tabela
 * de dispersão (pode-se já predefinir a tabela com o dobro do tamanho para evitar
 * redimensionamento). Gere aleatoriamente n valores inteiros usando a função rand;
 * insira o valor gerado no vetor e na tabela de dispersão; ao final, ordene o vetor.
 * Então, repita a geração dos n valores. Para garantir que a mesma sequência de
 * valores seja gerada, use um mesmo valor de semente (por exemplo, chamando
 * srand (0) antes de gerar o primeiro número de cada sequência). Para cada valor,
 * busque o valor no vetor usando busca binária. Para medir o tempo gasto para
 * fazer a busca dos n valores, use a função clock da biblioteca time.h, que reporta
 * o tempo de CPU gasto desde a invocação do processo (isto é, desde o início da
 * execução do programa), medidos em clocks por segundo ( CLOCKS_PER_SEC, uma
 * constante também definida em time.h). Interessa-nos a diferença de tempo de
 * CPU entre o início e o fim do procedimento que queremos medir. Em seguida,
 * repita o mesmo procedimento, gerando e buscando os n valores agora na tabela de
 * dispersão, medindo o tempo de execução. Imprima e compare os tempos de busca
 * de cada estratégia. Use diferentes valores de n e verifique a eficiência da tabela de
 * dispersão. O trecho de código a seguir ilustra a tomada de tempo de execução de
 * um procedimento.
 *
 * 		clock_t t0 = clock();
 *
 * 		... // procedimento que se deseja medir tempo de execução
 *
 * 		clock_t t1 = clock();
 * 		double t = (double)(t1-t0)/CLOCKS_PER_SEC; // tempo (seg)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "hash_int.h"
#include "vetor_int.h"

enum tipo { VET, HSH };

static int cb_hash(int v){
	return v;
}

static int cb_cmp_int(const void *v1, const void *v2)
{
	int *p1 = (int *)v1;
	int *p2 = (int *)v2;
	return *p1 - *p2;
}

static double tempo(int n, void *v, enum tipo t)
{
	time_t t0, t1;

	srand(0);
	t0 = clock();
	for (int i = 0; i < n; i++) {
		int r = rand();
		if(VET == t){
			assert(vet_busca((Vetor*)v,r));
		}else{
			assert(hsh_busca((Hash*)v,r));
		}
	}
	t1 = clock();
	return (double)(t1 - t0) / CLOCKS_PER_SEC;
}

int main(void)
{
	int n, min=101, max=997;
	double t;
	Hash *hsh;
	Vetor *vet;

	while (1) { 
		srand(time(NULL));
		n = (rand() % (max - min + 1)) + min;
		hsh = hsh_cria(2 * n,cb_hash);
		vet = vet_cria(n, cb_cmp_int);

		srand(0);
		for (int i = 0; i < n; i++) {
			int r = rand();
			vet_insere(vet,r);
			hsh_insere(hsh, r);
		}
		vet_ordena(vet);

		t = tempo(n, vet,VET);
		printf("Tempo de busca em vetor para %d elementos: %f\n", n, t);
		t = tempo(n, hsh,HSH);
		printf("Tempo de busca em hash para %d elementos: %f\n", n, t);
		getchar();

		hsh_libera(hsh);
		vet_libera(vet);
	}
	return 0;
}
