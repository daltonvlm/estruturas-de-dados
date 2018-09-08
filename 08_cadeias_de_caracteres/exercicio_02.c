/*
 * Implemente uma função que receba uma string como parâmetro e retorne como
 * resultado o número de vogais nessa string. Essa função deve obedecer ao protótipo:
 *
 *      int conta_vogais (char* str);
 */

int conta_vogais(char *str)
{
	int n = 0;
	char c, v;
	char *p, *vogais = "aeiou";
	while (c = *str++) {
		p = vogais;
		while (v = *p++) {
			if (c == v) {
				n++;
				break;
			}
		}
	}
	return n;
}
