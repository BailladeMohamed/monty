#include "monty.h"

/**
 * pall - prints stack
 * @s: stack given by main in start.c
 * @cnt: amount of lines
 */
void pall(stack_t **s, unsigned int cnt __attribute__((unused)))
{
	printstk(*s);
}
