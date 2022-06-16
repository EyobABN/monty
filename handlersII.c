#include "monty.h"

/**
 * addHandler - handles the nop opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void addHandler(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	printf("%s %s\n", argv[0], argv[1]);
}

/**
 * nopHandler - handles the nop opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void nopHandler(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	printf("%s %s\n", argv[0], argv[1]);
}
