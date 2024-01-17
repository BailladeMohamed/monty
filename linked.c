#include "monty.h"

/**
 * queue - adds a node to a stack_t stack in queue
 * @s: stack head
 * @nod: number of the node
 * Return: newly created node, if memory allocation fails,
 *			the function will return NULL
 */
stack_t *queue(stack_t **s, const int nod)
{
	stack_t *n = malloc(sizeof(stack_t));
	stack_t *cur = *s;

	if (!n)
	{
		free(n);
		return (NULL);
	}
	n->n = nod;

	if (!*s)
	{
		n->next = NULL;
		n->prev = NULL;
		*s = n;
		return (n);
	}
	while (cur)
	{
		if (!cur->next)
		{
			n->next = NULL;
			n->prev = cur;
			cur->next = n;
			break;
		}
		cur = cur->next;
	}
	return (n);
}

/**
 * addnode - adds a node to the start of a stack_t stack
 * @s: stack head
 * @num: number for new node
 * Return: newly created node, if creation fails return NULL
 */

stack_t *addnode(stack_t **s, const int num)
{
	stack_t *n = malloc(sizeof(stack_t));

	if (!n)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(n);
		return (NULL);
	}
	n->n = num;

	n->next = *s;
	n->prev = NULL;
	if (*s)
		(*s)->prev = n;
	*s = n;
	return (n);
}

/**
 * printstk - prints contents of a stack_t stack
 * @s: stack head
 * Return: number of elements of the list
 */

size_t printstk(const stack_t *s)
{
	size_t i = 0;

	while (s)
	{
		printf("%d\n", s->n);
		s = s->next;
		i++;
	}
	return (i);
}

/**
 * freestk - frees a dlistint_t linked list
 * @s: list head
 */

void freestk(stack_t *s)
{
	stack_t *cur = s;
	stack_t *nxt;

	if (s)
	{
		nxt = s->next;
		while (cur)
		{
			free(cur);
			cur = nxt;
			if (nxt)
				nxt = nxt->next;
		}
	}
}
