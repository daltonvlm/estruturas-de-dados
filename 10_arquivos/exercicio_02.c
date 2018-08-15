/*
 * Considere a existência de um arquivo texto, denominado "turma.txt", com um
 * cadastro de uma turma. Para cada aluno da turma, existem duas linhas no arquivo:
 * na primeira linha, encontra-se o nome do aluno; na linha seguinte, encontram-se as
 * duas notas obtidas pelo aluno. Considere que podem existir linhas em branco no
 * arquivo. Um exemplo deste arquivo é mostrado a seguir:
 *
 *      *************************************
 *      * Fulano Pereira                    *
 *      * 9.0 8.0                           *
 *      * Beltrano Silva                    *
 *      * 4.0 5.0                           *
 *      *                                   *
 *      * Sicrano Santos                    *
 *      * 3.0 7.0                           *
 *      * Fulana Souza                      *
 *      * 4.0 4.0                           *
 *      *                                   *
 *      * Maria Paula                       *
 *      * 6.0 7.0                           *
 *      *************************************
 *
 * Escreva um programa completo que leia o conteúdo do arquivo ("turma.txt") com
 * o formato anterior e crie outro arquivo, com o nome "aprovados.txt", com a lista
 * dos alunos que obtiveram médias maiores ou iguais a 5.0, seguindo a mesma ordem
 * do arquivo de entrada. Cada linha do arquivo de saída deve conter o nome e a
 * média obtida pelo aluno. Se esse arquivo anterior fosse usado num exemplo, a
 * saída obtida seria:
 *
 *      *************************************
 *      * Fulano Pereira        8.5         *
 *      * Sicrano Santos        5.0         *
 *      * Maria Paula           6.5         *
 *      *************************************
 *
 * Se o arquivo de entrada não puder ser aberto, deve-se imprimir a mensagem "Erro"
 * na tela e abortar o programa. Pode-se considerar que sempre será possível abrir o
 * arquivo de saída.
 */

#include <stdio.h>
#include <string.h>

#define MEDIA 5

int main(void)
{
	char buf[121];
	FILE *in, *out;

	in = fopen("turma.txt", "rt");
	if (!in) {
		puts("Erro");
		return 1;
	}
	out = fopen("aprovados.txt", "wt");

	while (fgets(buf, sizeof(buf), in)) {
		char nome[81];
		float n1, n2, media;
		int r;

		if (1 == sscanf(buf, " %80s", nome)) {
			if (fgets(buf, sizeof(buf), in)) {
				r = sscanf(buf, "%f %f", &n1, &n2);

				if (2 == r) {
					media = (n1 + n2) / 2;
					if (media >= MEDIA) {
						fprintf(out, "%s\t\t%f\n", nome,
							media);
					}
				}
			}
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
