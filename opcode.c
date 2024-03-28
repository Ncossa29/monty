#include "monty.h"

/**
 * opcode - function of builtins
 * @stack: stack provided by main file
 * @str: the string
 * @line_cnt: number of lines
 * Return: void
 */
void opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int y = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[y].opcode)
	{
		if (strcmp(op[y].opcode, str) == 0)
		{
			op[y].f(stack, line_cnt);
			return;
		}
		y++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	status = EXIT_FAILURE;
}
