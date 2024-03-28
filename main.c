#include "monty.h"
#include <stdio.h>

/**
 * error_handle - prints error message and exits
 * Return: void
 */
void error_handle(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - prints file errors mgs
 * @argv: argv given by manin
 * Return: void
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
int status = 0;

/**
 * main - entry point
 * @argv: list of arguments passed to the program
 * @argc: number of aruments
 * Return: void
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t bufl = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int lines = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_handle();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (getline(&buffer, &bufl, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			lines++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			lines++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, lines);
		lines++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}
