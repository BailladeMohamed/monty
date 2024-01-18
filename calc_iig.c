#include "monty.h"

/**
 * sub_ig -  subs the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Int representing ln
 */
void sub_ig(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		eror1(8, line_number, "sub");

	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_ig - divs the top two elements of the stack.
 * @stack: Pointer to top node
 * @line_number: Intrep the line number
 */
void div_ig(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		eror1(8, line_number, "div");

	if ((*stack)->n == 0)
		eror1(9, line_number);
	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_ig - muls the top two elements of the stack.
 * @stack: Pointer to top node of the stck.
 * @line_number: Int rep the line number
 */
void mul_ig(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		eror1(8, line_number, "mul");

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_c - coms the top two elements of the stack.
 * @stack: Pointer to top node
 * @line_number: Int rep the line number
 */
void mod_c(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		eror1(8, line_number, "mod");

	if ((*stack)->n == 0)
		eror1(9, line_number);
	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
