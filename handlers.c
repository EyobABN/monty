#include "monty.h"

/**
 * pushHandler - handles the push opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pushHandler(stack_t **stack, unsigned int line_number)
{
	if (argv[1] == NULL || is_number(argv[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_entire_arr(argv);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	insert_node_at_index(stack, 0, atoi(argv[1]));
}


/**
 * pallHandler - handles the pall opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pallHandler(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	print_stack(*stack);
}


/**
 * pintHandler - handles the pint opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pintHandler(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	printf("%s %s\n", argv[0], argv[1]);
}


/**
 * popHandler - handles the pop opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void popHandler(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	printf("%s %s\n", argv[0], argv[1]);
}

/**
 * swapHandler - handles the swap opcode
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void swapHandler(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	printf("%s %s\n", argv[0], argv[1]);
}
