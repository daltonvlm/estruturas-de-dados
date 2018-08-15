/*
 * Considerando novamente o tipo Funcionario definido na Questão 1, escreva uma
 * função que imprima os nomes dos cinco funcionários com maiores salários, sendo o
 * salário de um funcionário igual ao número de horas trabalhadas no mês vezes o valor
 * de sua hora de trabalho. Assuma que não existem dois funcionários com o mesmo
 * salário. A função deve receber como parâmetros o número total de funcionários e
 * um vetor que armazena ponteiros para estruturas do tipo Funcionario, de acordo
 * com o protótipo definido a seguir:
 *
 * 		void imprime_marajas (int n, Funcionario** vet);
 * 
 * Dica: Sua função pode primeiro ordenar o vetor em ordem decrescente de salários,
 * usando alguma das técnicas de ordenação apresentadas.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario Funcionario;
struct funcionario {
	char nome[81];
	float valor_hora;
	int horas_mes;
};

static float salario(Funcionario * pf)
{
	return pf->valor_hora * pf->horas_mes;
}

static int cmp_salario_inv(const void *p1, const void *p2)
{
	Funcionario **pp1 = (Funcionario **) p1;
	Funcionario **pp2 = (Funcionario **) p2;

	return salario(*pp2) - salario(*pp1);
}

void imprime_marajas(int n, Funcionario ** vet)
{
	qsort(vet, n, sizeof(Funcionario *), cmp_salario_inv);
	for (int i = 0; i < 5 && i < n; i++) {
		puts(vet[i]->nome);
	}
}

int main(void)
{
	Funcionario vf[7] = {
		{"A", 50, 60},
		{"B", 40, 80},
		{"C", 30, 120},
		{"D", 50, 50},
		{"E", 50, 60},
		{"F", 60, 200},
		{"G", 90, 60}
	};
	Funcionario *vpf[] =
	    { vf, vf + 1, vf + 2, vf + 3, vf + 4, vf + 5, vf + 6 };

	for (int i = 0; i < 7; i++) {
		printf("Nome: %s\tSalario: %.2f\n", vf[i].nome,
		       salario(vf + i));
	}
	imprime_marajas(7, vpf);
	return 0;
}
