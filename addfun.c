#include "monty.h"

/**
 * t_add - Adds the top two elements of the stack.
 * @stack: Pointer to dtop node of the stack.
 * @line_number: Int rep the lin num
 */
void t_add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		eror1(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
