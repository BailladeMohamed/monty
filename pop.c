#include "monty.h"

/**
* pop - pops the very top element of the stack
* @s: stack given by main in start.c
* @cnt: line number for error messages
*/
void pop(stack_t **s, unsigned int cnt)
{
	stack_t *temp = NULL;

	if (!s || !*s)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", cnt);
		exit(EXIT_FAILURE);
	}
	temp = (*s)->next;
	free(*s);
	*s = temp;
	if (!*s)
		return;
	(*s)->prev = NULL;
}
