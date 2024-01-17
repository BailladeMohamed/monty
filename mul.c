#include "monty.h"

/**
 * mul_ - divides next top value by top value
 * @s: stack given by main
 * @cnt: line counter
 */

void mul_(stack_t **s, unsigned int cnt)
{
	int prod;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", cnt);
		exit(EXIT_FAILURE);
		return;
	}

	prod = ((*s)->next->n) * ((*s)->n);
	pop(s, cnt);
	(*s)->n = prod;
}
