#include "monty.h"

/**
* rotr - rotates last node of a stack_t stack
* @s: stack head
* @cnt: line count
*/

void rotr(stack_t **s, unsigned int cnt)
{
	stack_t *bot;
	stack_t *prv;

	(void) cnt;
	if (!s || !*s || !(*s)->next)
		return;
	bot = *s;
	while (bot->next)
		bot = bot->next;
	prv = bot->prev;
	bot->next = *s;
	bot->prev = NULL;
	prv->next = NULL;
	(*s)->prev = bot;
	*s = bot;
}
