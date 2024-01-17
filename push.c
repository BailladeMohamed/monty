#include "monty.h"

/**
 * push - push element into the stack
 * @s: stack given by main
 * @cnt: amount of lines
 */

void push(stack_t **s, unsigned int cnt)
{
	char *i = global.arg;

	if ((isdigit(i)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", cnt);
		exit(EXIT_FAILURE);
	}
	if (global.data == 1)
	{
		if (!addnode(s, atoi(global.arg)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!queue(s, atoi(global.arg)))
			exit(EXIT_FAILURE);
	}
}
