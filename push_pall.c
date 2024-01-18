#include "monty.h"


/**
 * stack_add - Adds a node to the stack.
 * @neu_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void stack_add(stack_t **neu_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (neu_node == NULL || *neu_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *neu_node;
		return;
	}
	tmp = head;
	head = *neu_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * stack_print - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void stack_print(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
