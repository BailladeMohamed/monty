#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE 200810L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct hlp - argument for the current opcode
* @data: stack mode, stack (default) and queue
* @arg: arguments of the string
*/
typedef struct hlp
{
	int data;
	char *arg;
} hlp;
hlp global;

#define INSTRUC \
{ \
	{"push", push}, \
	{"pall", pall}, \
	{"pint", pint}, \
	{"pop", pop}, \
	{"swap", swap}, \
	{"nop", nop}, \
	{"div", div_}, \
	{"mul", mul_}, \
	{"add", add_}, \
	{"sub", sub_}, \
	{"mod", mod_}, \
	{"pchar", pchar}, \
	{"pstr", pstr}, \
	{"rotl", rotl}, \
	{"rotr", rotr}, \
	{NULL, NULL} \
}

void div_(stack_t **s, unsigned int cnt);
void add_(stack_t **s, unsigned int cnt);
void sub_(stack_t **s, unsigned int cnt);
void mul_(stack_t **s, unsigned int cnt);
void mod_(stack_t **s, unsigned int cnt);

void push(stack_t **s, unsigned int cnt);
void pall(stack_t **s, unsigned int cnt);
void pint(stack_t **s, unsigned int cnt);
void swap(stack_t **s, unsigned int cnt);
void pop(stack_t **s, unsigned int cnt);
void nop(stack_t **s, unsigned int cnt);

void pchar(stack_t **s, unsigned int cnt);
void pstr(stack_t **s, unsigned int cnt);
void rotl(stack_t **s, unsigned int cnt);
void rotr(stack_t **s, unsigned int cnt);

stack_t *addnode(stack_t **s, const int num);
stack_t *queue(stack_t **s, const int nod);
void freestk(stack_t *s);
size_t printstk(const stack_t *s);

void fileer(char *av);
void erusage(void);

int isdig(char *str);
int isnum(char *str);

void op_code(stack_t **s, char *str, unsigned int cnt);

#endif
