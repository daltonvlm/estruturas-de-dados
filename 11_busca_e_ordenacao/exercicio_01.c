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
