#include <stdio.h>
#include <stdlib.h>

typedef void (*func) (void);
typedef int *Pint;

void foo(void)
{
	puts("foo");
}

int main(void)
{
	void (*f(void)) (void) {
		return foo;
	}
	func x = f();
	x();
	return 0;
}
