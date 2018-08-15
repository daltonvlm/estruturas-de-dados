#ifndef HSORTGEN_H
#define HSORTGEN_H
void hsort(void *v, size_t n, size_t size,
	   int (*cmp) (const void *, const void *));
#endif
