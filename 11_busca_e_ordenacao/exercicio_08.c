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

typedef struct funcionario Funcionario;
struct funcionario {
	char nome[81];
	int dia, mes;
};

static int cmp(const void *p1, const void *p2)
{
	Funcionario *pf1 = *(Funcionario **) p1;
	Funcionario *pf2 = *(Funcionario **) p2;

	/*
	 * return pf1->mes-pf2->mes 
	 * || pf1->dia-pf2->dia 
	 * || strcmp(pf1->nome,pf2->nome);
	 *      
	 */

	if (pf1->mes != pf2->mes) {
		return pf1->mes - pf2->mes;
	}
	if (pf1->dia != pf2->dia) {
		return pf1->dia - pf2->dia;
	}
	return strcmp(pf1->nome, pf2->nome);
}

void ordena(int n, Funcionario ** vpf)
{
	qsort(vpf, n, sizeof(Funcionario *), cmp);
}

static int cmp_mes(const void *p1, const void *p2)
{
	int *pmes = (int *)p1;
	Funcionario **ppf = (Funcionario **) p2;
	return *pmes - (*ppf)->mes;
}

void aniversariantes_do_mes(int n, Funcionario ** vpf, int mes)
{
	Funcionario **ppf =
	    bsearch(&mes, vpf, n, sizeof(Funcionario *), cmp_mes);
	if (ppf) {
		aniversariantes_do_mes(ppf - vpf, vpf, mes);
		printf("%s\n", (*ppf)->nome);
		aniversariantes_do_mes(n - (int)(ppf - vpf) - 1, ppf + 1, mes);
	}
}

int main(void)
{
	Funcionario vf[8] = {
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

	ordena(8, vpf);
	for (int i = 0; i < 8; i++) {
		printf("%s\t%02d/%02d\n", vpf[i]->nome, vpf[i]->dia,
		       vpf[i]->mes);
	}
	puts("");

	aniversariantes_do_mes(8, vpf, 2);

	return 0;
}
