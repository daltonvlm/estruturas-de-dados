/*
 * Escreva uma função que receba como parâmetros duas strings e um caractere sepa-
 * rador. A função deve criar a string que representa a concatenação das duas strings
 * de entrada, usando o caractere como separador. Por exemplo, se forem passadas
 * as strings "ex" e "aluno", e o caractere hífen '-', deve-se ter como valor de retorno
 * a string "ex-aluno". O protótipo da função deve ser:
 *
 *      char* concatena (char* s1, char* s2, char sep);
 */

char *concatena(char *s1, char *s2, char sep)
{
	char *r = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (r) {
		char *t = r;
		while (*t++ = *s1++) ;
		*(t - 1) = sep;
		while (*t++ = *s2++) ;
	}
	return r;
}
