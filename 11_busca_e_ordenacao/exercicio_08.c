/*
 * Considere que uma empresa quer ter acesso a lista dos aniversários de seus funci-
 * onários. Cada funcionário, neste vetor, será identificado pelo nome e dia/mês de
 * aniversário.
 *
 * 		typedef struct funcionario Funcionario;
 * 		struct funcionario {
 * 			char nome[81];
 * 			int dia, mes;
 * 		};
 *
 *	(a)	Implemente uma função que receba um vetor de ponteiros para o tipo apre-
 * 		sentado e ordene o vetor em ordem crescente de dia de aniversário. Ou seja,
 * 		use como critério de ordenação o mês; para valores de mês iguais, use o dia.
 * 		Se dois ou mais funcionários fizerem aniversário na mesma data, use a ordem
 * 		alfabética do nome como critério de desempate. Sua função de ordenação deve
 * 		obrigatoriamente fazer uso da função qsort da biblioteca padrão. Sua função
 * 		deve receber o número de funcionários e o vetor de ponteiros como parâmetros.
 *
 *	(b)	Implemente uma função que receba um vetor de ponteiros para os funcio-
 * 		nários, ordenado conforme o critério citado, e exiba na tela os nomes dos
 * 		aniversariantes do mês especificado. Sua função deve receber como parâme-
 * 		tros o número de funcionários, o vetor de ponteiros (já ordenado) e o mês que
 * 		se deseja consultar. Utilize o algoritmo de busca binária para procurar um
 * 		funcionário que faça aniversário no mês especificado. A partir desta posição,
 * 		percorra os elementos vizinhos no vetor para achar o início e o fim dos funcio-
 * 		nários que fazem aniversário no mesmo mês, e exiba seus nomes na tela, em
 * 		ordem do dia do aniversário.
 *
 *	(c)	Escreva uma função main para testar suas funções. A função deve definir
 *		um vetor de ponteiros para funcionários com os dados numa ordem qualquer,
 *		chamar a função de ordenação e, então, chamar a função para exibir os ani-
 *		versariantes de uma data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

typedef struct funcionario Funcionario;
struct funcionario {
	char nome[81];
	int dia, mes;
};

static int compara_data_nome(const void *v1, const void *v2)
{
	Funcionario **p1 = (Funcionario **) v1;
	Funcionario **p2 = (Funcionario **) v2;
	int mes = (*p1)->mes - (*p2)->mes;
	int dia = (*p1)->dia - (*p2)->dia;
	return (mes ? mes : (dia ? dia : (strcmp((*p1)->nome, (*p2)->nome))));
}

static int compara_mes(const void *v1, const void *v2)
{
	int *info = (int *)v1;
	Funcionario **elem = (Funcionario **) v2;
	return *info - (*elem)->mes;
}

void ordena(int n, Funcionario ** v)
{
	qsort(v, n, sizeof(Funcionario *), compara_data_nome);
}

void imprime_aniversariantes(int n, Funcionario ** v, int mes)
{
	Funcionario **p =
	    (Funcionario **) bsearch(&mes, v, n, sizeof(Funcionario *),
				     compara_mes);
	if (p) {
		imprime_aniversariantes(p - v, v, mes);
		printf("%s\n", (*p)->nome);
		imprime_aniversariantes(n - (int)(p - v) - 1, p + 1, mes);
	}
}

int main(void)
{
	Funcionario vf[N] = {
		{"Funcionario H", 4, 4},
		{"Funcionario B", 2, 2},
		{"Funcionario G", 3, 3},
		{"Funcionario D", 4, 4},
		{"Funcionario C", 3, 3},
		{"Funcionario F", 2, 2},
		{"Funcionario E", 1, 1},
		{"Funcionario A", 1, 1}
	};
	Funcionario *vpf[] = { vf, vf + 1, vf + 2,
		vf + 3, vf + 4, vf + 5, vf + 6, vf + 7
	};
	int mes = 4;

	ordena(N, vpf);
	for (int i = 0; i < N; i++) {
		printf("%s\t%02d/%02d\n", vpf[i]->nome, vpf[i]->dia,
		       vpf[i]->mes);
	}
	printf("\nAniversariantes do mes %02d:\n", mes);
	imprime_aniversariantes(N, vpf, mes);
	return 0;
}
