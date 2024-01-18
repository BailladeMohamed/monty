#include "monty.h"

/**
 * pin - Prints the top node of the stack.
 * @stack: Pointer to a pointer to top of the stack.
 * @line_number: Int representing the line number
 */
void pin(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		eror1(6, line_number);
	printf("%d\n", (*stack)->n);
}
