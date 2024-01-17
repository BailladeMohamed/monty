#include "monty.h"

/**
 * div_ - divides next top value by the top value
 * @s: stack given by main
 * @cnt: line counter
 */

void div_(stack_t **s, unsigned int cnt)
{
	int quot;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", cnt);
		exit(EXIT_FAILURE);
	}
	if (((*s)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cnt);
		exit(EXIT_FAILURE);
	}

	quot = ((*s)->next->n) / ((*s)->n);
	pop(s, cnt);
	(*s)->n = quot;
}
