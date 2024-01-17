#include "monty.h"

/**
 * sub_ -  substracts first two nodes of the stack
 * @s: stack given by main
 * @cnt: line counter
 */

void sub_(stack_t **s, unsigned int cnt)
{
	int diff;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", cnt);
		exit(EXIT_FAILURE);
	}

	diff = ((*s)->next->n) - ((*s)->n);
	pop(s, cnt);
	(*s)->n = diff;
}
