#include "monty.h"

/**
 * pint - print value at the top of the stack
 * @s: stack given by main in start.c
 * @cnt: amount of lines
 */
void pint(stack_t **s, unsigned int cnt)
{
	if (!s || !(*s))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", cnt);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
}
