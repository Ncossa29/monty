#include "monty.h"

/**
 * push - pushs element into the stack
 * @stack: the stack provided in the main c
 * @line_nu: number of lines counted
 * Return: void
 */
void push(stack_t **stack, unsigned int line_nu)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_nu);
		status = EXIT_FAILURE;
		return;
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}
