#include "monty.h"

char **argv = NULL;
/**
 * main - entry point
 * @ac: the argument count
 * @av: the argument vector
 *
 * Return: 0 upon success, 1 upon failure
 */
int main(int ac, char **av)
{
	FILE *fptr;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	ssize_t nread;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fptr = fopen(av[1], "r");
	if (fptr == NULL)
	{
		write(2, "Error: Can't open file ", 23);
		write(2, av[1], strlen(av[1]));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, fptr)) != -1)
	{
		line[strlen(line) - 1] = '\0';	/* remove newline char from the end */
		argv = mkargv(line);
		if (argv[0] != NULL)
			exec_instruction(argv[0], &stack, line_number);
		free_entire_arr(argv);
		argv = NULL;
		line_number++;
	}
	free(line);
	free_stack(stack);
	fclose(fptr);
	return (0);
}
