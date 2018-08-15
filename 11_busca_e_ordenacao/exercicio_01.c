/*
 * Considere um tipo que representa um funcionario de uma empresa, definido pela
 * estrutura a seguir:
 *
 *      typedef struct funcionario Funcionario;
 *      struct funcionario {
 *          char nome[81];      // nome do funcionario
 *          float valor_hora;   // valor da hora de trabalho em Reais
 *          int horas_mes;      // horas trabalhadas em um mês
 *      };
 *
 * Escreva uma função que faça uma busca binária em um vetor de ponteiros para
 * o tipo Funcionario, cujos elementos estão em ordem alfabética dos nomes dos
 * funcionários. Esta função deve receber como parâmetros o número de funcionários,
 * o vetor e o nome do funcionário que se deseja buscar, e deve ter como valor de
 * retorno um ponteiro para o registro do funcionário procurado. Se não houver um
 * funcionário com o nome procurado, a função deve retornar NULL. A função deve
 * obedecer ao seguiinte protótipo:
 *
 * 		Funcionario* busca (int n, Funcionario** v, char* nome);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;
struct funcionario {
	char nome[81];
	float valor_hora;
	int horas_mes;
};

Funcionario *busca(int n, Funcionario ** v, char *nome)
{
	int i = 0;
	int f = n - 1;

	while (i <= f) {
		int m = (i + f) / 2;
		int cmp = strcmp(nome, v[m]->nome);

		if (cmp < 0) {
			f = m - 1;
		} else if (cmp > 0) {
			i = m + 1;
		} else {
			return v[m];
		}
	}
	return NULL;
}

int main(void)
{
	Funcionario vf[7] = {
		{"Funcionario A", 0, 0},
		{"Funcionario B", 0, 0},
		{"Funcionario C", 0, 0},
		{"Funcionario D", 0, 0},
		{"Funcionario E", 0, 0},
		{"Funcionario F", 0, 0},
		{"Funcionario G", 0, 0}
	};
	Funcionario *vpf[7] =
	    { vf, vf + 1, vf + 2, vf + 3, vf + 4, vf + 5, vf + 6 };
	char nome[81];

	while (1) {
		printf("Nome: ");
		scanf(" %80[^\n]", nome);

		Funcionario *pf = busca(7, vpf, nome);
		if (pf) {
			printf("\"%s\" encontrado\n", pf->nome);
		} else {
			printf("\"%s\" nao encontrado\n", nome);
		}
	}
	return 0;
}
