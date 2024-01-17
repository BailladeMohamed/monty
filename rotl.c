#include "monty.h"

/**
* rotl - rotates the first element of the stack
* @s: stack head
* @cnt: line count
*/
void rotl(stack_t **s, unsigned int cnt)
{
	stack_t *l;
	stack_t *r;

	(void) cnt;
	if (!s || !*s || !(*s)->next)
		return;
	l = r = *s;

	while (r->next)
		r = r->next;
	r->next = l;
	l->prev = r;
	*s = l->next;
	(*s)->prev->next = NULL;
	(*s)->prev = NULL;
}
