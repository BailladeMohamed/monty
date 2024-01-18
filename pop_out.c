#include "monty.h"

/**
 * pop_lol - Adds a node
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line num
 */
void pop_lol(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		eror1(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
