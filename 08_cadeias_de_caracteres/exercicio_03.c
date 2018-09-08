/*
 * Implemente uma função que receba uma string como parâmetro e altere nessa
 * string as ocorrências de caracteres maiúsculos para minúsculos. Essa função deve
 * obedecer ao protótipo:
 *
 *      void minusculo (char* str);
 */

static int eh_maiusculo(char c)
{
	return c >= 'A' && c <= 'Z';
}

void minusculo(char *str)
{
	char c;
	int i = 0;
	while (c = str[i]) {
		if (eh_maiusculo(c)) {
			str[i] += 'a' - 'A';
		}
		i++;
	}
}
