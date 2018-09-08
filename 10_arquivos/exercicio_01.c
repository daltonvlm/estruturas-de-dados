/*
 * Considere um arquivo texto com as notas dos alunos de uma disciplina. Cada linha
 * do arquivo contém a matrícula de um aluno (cadeia de nove caracteres), seguida
 * pelos valores de suas três notas (P1, P2 e P3). Considere ainda que podem existir
 * linhas em branco no arquivo. Um exemplo desse formato é:
 *
 *     *************************
 *     * 9010087-2 2.0 4.3 6.5 *
 *     * 8820324-3 7.0 8.2 8.6 *
 *     *                       *
 *     * 9210478-5 6.0 7.5 7.8 *
 *     * 9020256-8 3.0 0.5 4.2 *
 *     *************************
 *
 * Escreva uma função que receba como parâmetro o número de matrícula de um
 * aluno e o nome de um arquivo com as notas de uma disciplina no formato descrito,
 * e retorne a média do aluno na disciplina. A média de um aluno é calculada pela
 * fórmula (P1 + P2 + P3)/3. O protótipo da função deve ser:
 *
 *      float media (char* mat, char* nome_arquivo):
 *
 * Caso o número da matrícula passado como parâmetro não seja encontrado no ar-
 * quivo, a função deve retornar -1.0. Se não for possível abrir o arquivo de entrada,
 * a função deve imprimir a mensagem "Erro" e terminar a execução do programa.
 */

float media(char *mat, char *nome_arquivo)
{
	char linha[81], m[10];
	float p1, p2, p3, md = -1;
	FILE *fp = fopen(nome_arquivo, "rt");
	if (!fp) {
		fprintf(stderr, "Erro\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(linha, sizeof(linha), fp)) {
		if (4 == sscanf(linha, "%9s%f%f%f", m, &p1, &p2, &p3)) {
			if (!strcmp(m, mat)) {
				md = (p1 + p2 + p3) / 3;
				break;
			}
		}
	}
	fclose(fp);
	return md;
}
