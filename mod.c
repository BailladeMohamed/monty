#include "monty.h"

/**
 * mod_ - computes remainder of division
 * @s: stack given by main
 * @cnt: line counter
 */

void mod_(stack_t **s, unsigned int cnt)
{
	int rem;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", cnt);
		exit(EXIT_FAILURE);
	}
	if (((*s)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cnt);
		exit(EXIT_FAILURE);
	}
	rem = ((*s)->next->n) % ((*s)->n);
	pop(s, cnt);
	(*s)->n = rem;
}
