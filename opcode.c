#include "monty.h"

/**
 * op_code - function in charge of running builtins
 * @s: stack given by main
 * @str: string to compare
 * @cnt: amount of lines
 */
void op_code(stack_t **s, char *str, unsigned int cnt)
{
	int c = 0;

	instruction_t op[] = INSTRUC;

	if (!strcmp(str, "stack"))
	{
		global.data = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data = 0;
		return;
	}
	while (op[c].opcode)
	{
		if (strcmp(op[c].opcode, str) == 0)
		{
			op[c].f(s, cnt);
			return;
		}
		c++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", cnt, str);
	exit(EXIT_FAILURE);
}
