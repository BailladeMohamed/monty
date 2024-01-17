#include "monty.h"

/**
 * pstr - prints contents of stack_t stack as string
 * @s: stack given by main
 * @cnt: line counter
 */
void pstr(stack_t **s, unsigned int cnt __attribute__((unused)))
{
	stack_t *cur = *s;

	while (cur)
	{
		if (cur->n <= 0 || cur->n > 127)
			break;
		putchar((char) cur->n);
		cur = cur->next;
	}
	putchar('\n');
}
