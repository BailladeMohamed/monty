#include "monty.h"

/**
 * sep_line - Separates each line into tokens to know
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int sep_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		eror(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	func_finder(opcode, value, line_number, format);
	return (format);
}

/**
 * func_finder - find the appropriate function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void func_finder(char *opcode, char *value, int ln, int format)
{
	int x;
	int matched;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", stack_print},
		{"pint", pin},
		{"pop", pop_lol},
		{"swap", n_swaper},
		{"add", t_add},
		{"nop", nope_lol},
		{"sub", sub_ig},
		{"div", div_ig},
		{"mul", mul_ig},
		{"mod", mod_c},
		{"rotl", op_rotl},
		{"rotr", op_rotl},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (matched = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			b_called(func_list[x].f, opcode, value, ln, format);
			matched = 0;
		}
	}
	if (matched == 1)
		eror(3, ln, opcode);
}
#include "monty.h"
/**
 * b_called - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void b_called(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int called;
	int idx;

	called = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			called = -1;
		}
		if (val == NULL)
			eror(5, ln);
		for (idx = 0; val[idx] != '\0'; idx++)
		{
			if (isdigit(val[idx]) == 0)
				eror(5, ln);
		}
		node = neu_node(atoi(val) * called);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			q_add(&node, ln);
	}
	else
		func(&head, ln);
}
