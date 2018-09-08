/*
 * Implemente uma função que receba uma string como parâmetro e substitua as
 * ocorrências de uma letra pelo seu oposto no alfabeto, isto é, a <-> z, b <-> y, c <-> x
 * etc. Caracteres que não forem letras devem permanecer inalterados. Essa função
 * deve obedecer ao protótipo:
 *
 *      void string_oposta (char* str);
 */

static int eh_maiusculo_minusculo(char c)
{
	if (c >= 'A' && c <= 'Z') {
		return -1;
	}
	if (c >= 'a' && c <= 'z') {
		return 1;
	}
	return 0;
}

void string_oposta(char *str)
{
	char c;
	int letra;
	int i = 0;
	while (c = str[i]) {
		letra = eh_maiusculo_minusculo(c);
		if (letra) {
			int base = letra < 0 ? 'A' : 'a';
			int limite = base + 'z' - 'a';
			str[i] = limite - (c - base);
		}
		i++;
	}
}
