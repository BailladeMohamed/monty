#include "monty.h"

/**
 * swap -  swaps data from top to previous
 * @s: stack given by main
 * @cnt: amount of lines
 */
void swap(stack_t **s, unsigned int cnt)
{
	stack_t *temp = NULL;
	int tmp = 0;

	if (!s || !*s || !((*s)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", cnt);
		exit(EXIT_FAILURE);
	}
	temp = *s;
	tmp = temp->n;
	temp->n = tmp;
	temp->n = temp->next->n;
	temp->next->n = tmp;
}
