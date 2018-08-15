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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *converte(char *s)
{
	int n = strlen(s);
	char *r = (char *)malloc(n + 1);

	if (r) {
		int i = 0;
		for (int j = 0; j < n; j++) {
			if (('a' <= s[j] && s[j] <= 'z')
			    || ('A' <= s[j] && s[j] <= 'Z')) {
				r[i++] = s[j];
			}
		}
		r[i] = '\0';
	}
	return r;
}

int main(void)
{
	while (1) {
		char str[81], *r;
		scanf(" %80[^\n]", str);
		r = converte(str);
		if (r) {
			puts(r);
			free(r);
		}
	}
	return 0;
}
