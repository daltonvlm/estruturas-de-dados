/*
 * Implemente uma função que receba uma string como parâmetro e desloque os seus
 * caracteres uma posição para a direita. Por exemplo a string "casa" seria alterada
 * para "acas". Repare que o último caractere vai para o início da string. Essa função
 * deve obedecer ao protótipo:
 *
 *      void roda_string (char* str);
 */

void roda_string(char *str)
{
	char atual = str[0];
	int n = strlen(str);
	for (int i = 0; str[i]; i++) {
		int prox = (i + 1) % n;
		char tmp = str[prox];
		str[prox] = atual;
		atual = tmp;
	}
}
