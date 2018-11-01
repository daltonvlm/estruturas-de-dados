#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 7

char *zero[] = { "  ***  ",
	" *   * ",
	"*     *",
	"*     *",
	"*     *",
	" *   * ",
	"  ***  "
};

char *one[] = { " * ", "** ", " * ", " * ", " * ", " * ", "***" };
char *two[] = { " *** ", "*   *", "*  * ", "  *  ", " *   ", "*    ", "*****" };
char *three[] =
    { " *** ", "*   *", "    *", "  ** ", "    *", "*   *", " *** " };
char *four[] = { "   *  ", "  **  ", " * *  ", "*  *  ", "******", "   *  ",
	"   *  "
};
char *five[] =
    { "*****", "*    ", "*    ", " *** ", "    *", "*   *", " *** " };
char *six[] = { " *** ", "*    ", "*    ", "**** ", "*   *", "*   *", " *** " };
char *seven[] =
    { "*****", "    *", "   * ", "  *  ", " *   ", "*    ", "*    " };
char *eight[] =
    { " *** ", "*   *", "*   *", " *** ", "*   *", "*   *", " *** " };
char *nine[] =
    { " ****", "*   *", "*   *", " ****", "    *", "    *", "    *" };

char **digits[] =
    { zero, one, two, three, four, five, six, seven, eight, nine };

static int get_int(char *number, int col)
{
	char c = number[col];

	if (c >= '0' && c <= '9') {
		return c - '0';
	}

	fprintf(stderr, "err: '%c' in '%s'\n", c, number);
	exit(EXIT_FAILURE);
}

static void check(void *p)
{
	if (NULL == p) {
		fprintf(stderr, "err: memory not allocated\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: bigdigits <number>\n");
		exit(EXIT_FAILURE);
	}
	char *number = argv[1];
	int dim = 80;
	char *line = (char *)malloc(dim * sizeof(char) + 1);
	check(line);

	for (int row = 0; row < ROWS; row++) {
		line[0] = '\0';
		for (int col = 0; col < strlen(number); col++) {
			int i = get_int(number, col);
			char **digit = digits[i];
			if (strlen(line) + strlen(digit[row]) > dim) {
				dim *= 2;
				line =
				    (char *)realloc(line,
						    dim * sizeof(char) + 1);
				check(line);
			}
			strcat(line, digit[row]);
			strcat(line, "  ");
		}
		puts(line);
	}
	free(line);
	return 0;
}
