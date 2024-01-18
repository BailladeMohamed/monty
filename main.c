#include "monty.h"
stack_t *head;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	of(argv[1]);
	stack_free();
	return (0);
}

/**
 * neu_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *neu_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		eror(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * stack_free - Frees nodes in the stack
 */
void stack_free(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * q_add - Adds a node to the queue.
 * @neu_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void q_add(stack_t **neu_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *neu_node;
	(*neu_node)->prev = tmp;

}
