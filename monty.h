#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


/*task 0*/
void stack_add(stack_t **new_node, __attribute__((unused))unsigned int ln); /*push*/
void stack_print(stack_t **stack, unsigned int line_number); /*pall*/

/*main*/
int main(int argc, char *argv[]);
stack_t *neu_node(int n);
void stack_free(void);
void q_add(stack_t **neu_node, __attribute__((unused))unsigned int ln);
size_t lenofstr(const char *str);

/*o.r*/
void of(char *file_name);
void readf(FILE *fd);

/*error*/
void eror(int error_code, ...);
void eror1(int error_code, ...);

/*func*/
int sep_line(char *buffer, int line_number, int format);
void func_finder(char *opcode, char *value, int ln, int format);
void b_called(op_func func, char *op, char *val, int ln, int format);

/*head*/
extern stack_t *head;

/*pint*/
void pin(stack_t **stack, unsigned int line_number);

/*pop*/
void pop_lol(stack_t **stack, unsigned int line_number);

/*the ol swapin method*/
void n_swaper(stack_t **stack, unsigned int line_number);

/*add op*/
void t_add(stack_t **stack, unsigned int line_number);

/*useless*/
void nope_lol(stack_t **stack, unsigned int line_number);

/*calc*/
void sub_ig(stack_t **stack, unsigned int line_number);
void div_ig(stack_t **stack, unsigned int line_number);
void mul_ig(stack_t **stack, unsigned int line_number);
void mod_c(stack_t **stack, unsigned int line_number);

/*rotl rotr*/
void op_rotr(stack_t **stack, __attribute__((unused))unsigned int ln);
void op_rotl(stack_t **stack, __attribute__((unused))unsigned int ln);



#endif
