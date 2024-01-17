#include "monty.h"

/**
 * add_ -  adds first two nodes of the stack
 * @s: stack given by main
 * @cnt: line counter
 */
void add_(stack_t **s, unsigned int cnt)
{
	int sum;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cnt);
		exit(EXIT_FAILURE);
	}
	sum = ((*s)->next->n) + ((*s)->n);
	pop(s, cnt);
	(*s)->n = sum;
}
