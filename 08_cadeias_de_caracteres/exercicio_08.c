/*
 * Escreva uma função em C que receba como parâmetro uma string e retorne uma
 * nova string com somente as letras do alfabeto (serão removidos caracteres especiais,
 * espaços, dígitos etc.). Por exemplo, se for passada como parâmetro a cadeia de
 * caracteres "# Mat.: 39838-0 DC", a função deve retornar a cadeia "MatDC". A
 * string passada como parâmetro não pode ser alterada. Essa função deve ter o
 * seguinte protótipo:
 *
 *      char* converte (char* s);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int eh_letra(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char *converte(char *s)
{
	char *conv, def[81];
	char c;
	int i = 0;
	while ((c = *s++) && i < 80) {
		if (eh_letra(c)) {
			def[i++] = c;
		}
	}
	def[i++] = '\0';
	conv = (char *)malloc(i);
	if (conv) {
		strcpy(conv, def);
	}
	return conv;
}

int main(void)
{
	char s[81];
	char *conv;
	while (1) {
		printf("Texto: ");
		scanf(" %80[^\n]", s);
		conv = converte(s);
		if (conv) {
			puts(conv);
			free(conv);
		}
	}
	return 0;
}
