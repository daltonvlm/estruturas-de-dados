/*
 * Considere um tipo que representa um funcionário e uma empresa, definido pela
 * estrutura a seguir;
 *
 *      typedef struct funcionario Funcionario;
 *      struct funcionario {
 *          char nome[81];      // nome do funcionário
 *          float valor_hora;   // valor da hora de trabalho em Reais
 *          int horas_mes;      // horas trabalhadas em um mês
 *      };
 *
 * Escreva uma função em C que preencha um vetor de ponteiros para Funcionario
 * com os dados lidos de um arquivo texto. Essa função deve receber como parâmetros
 * o vetor de ponteiros para Funcionario e o nome do arquivo de entrada. Nesse
 * arquivo de entrada, os dados de cada funcionário são armazenados em duas linhas:
 * uma com o seu nome (cadeia com até 80 caracteres), e outra com o valor de sua
 * hora de trabalho e com o número de horas trabalhadas em um mês (nessa ordem).
 * Um exemplo desse formato é mostrado a seguir.
 *
 *      *****************************
 *      * João da Silva             *
 *      * 15.0 160                  *
 *      * Manuel Santos             *
 *      * 15.0 80                   *
 *      * Fulana de Tal             *
 *      * 23.5 40                   *
 *      *****************************
 *
 * A função implementada deve ter o seguinte protótipo:
 *
 *      void carrega (int n, Funcionario** vet, char* arquivo);
 *
 * Considere que: não existem linhas em branco no arquivo; o parâmetro vet já vem
 * com todas as suas posições inicializadas com NULL; o comprimento do vetor (parâ-
 * metro n) é no mínimo igual à quantidade de registros de funcionários no arquivo
 * de entrada; se não for possível abrir o arquivo, a função deve imprimir a mensagem
 * "Erro" e terminar a execução do programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct funcionario Funcionario;
struct funcionario {
	char nome[81];
	float valor_hora;
	int horas_mes;
};

void carrega(int n, Funcionario ** vet, char *arquivo)
{
	int i = 0;
	char buf[121];
	FILE *in = fopen(arquivo, "rt");

	if (!in) {
		puts("Erro");
		exit(1);
	}

	while (fgets(buf, sizeof(buf), in) && i < n) {
		char nome[81];
		float vh;
		int hm;

		if (1 == sscanf(buf, " %80[^\n]", nome)) {
			if (fgets(buf, sizeof(buf), in)) {
				if (2 == sscanf(buf, "%f %d", &vh, &hm)) {
					Funcionario *f = (Funcionario *)
					    malloc(sizeof(Funcionario));
					if (f) {
						strcpy(f->nome, nome);
						f->valor_hora = vh;
						f->horas_mes = hm;
						vet[i++] = f;
					}
				}
			}
		}
	}
	fclose(in);
}

int main(void)
{
	Funcionario *vet[N] = { NULL };
	carrega(N, vet, "funcionarios.txt");

	for (int i = 0; i < N; i++) {
		if (vet[i]) {
			printf("Nome: %s\n", vet[i]->nome);
			printf("Valor/hora: %.2f\n", vet[i]->valor_hora);
			printf("Hora/mes: %d\n\n", vet[i]->horas_mes);
			free(vet[i]);
			vet[i] = NULL;
		}
	}
	return 0;
}
