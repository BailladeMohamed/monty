#include "monty.h"

/**
 * pchar - prints int at the top of the stack as char
 * @s: stack given by main
 * @cnt: amount of line
 */
void pchar(stack_t **s, unsigned int cnt)
{
	if (!s || !(*s))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", cnt);
		exit(EXIT_FAILURE);
	}
	if ((*s)->n < 0 || (*s)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", cnt);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*s)->n);
}
