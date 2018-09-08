/*
 * Implemente uma função que receba uma string como parâmetro e substitua todas as
 * letras por suas sucessoras no alfabeto. Por exemplo, a string "Casa" seria alterada
 * para "Dbtb". A letra z deve ser substituida pela letra a (e Z por A). Caracteres
 * que não forem letras devem permanecer inalterados. Essa função deve obedecer ao
 * protótipo:
 *
 *      void shift_string (char* str);
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

void shift_string(char *str)
{
	char c;
	int letra;
	int nletras = 'z' - 'a' + 1;
	int i = 0;

	while (c = str[i]) {
		letra = eh_maiusculo_minusculo(c);
		if (letra) {
			int base = letra < 0 ? 'A' : 'a';
			str[i] = base + (c - base + 1) % nletras;
		}
		i++;
	}
}
