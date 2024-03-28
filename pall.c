#include "monty.h"

/**
 * pall - prints the stack
 * @stack: the stack provided by main file
 * @linen: ammount of lines
 * Return: void
 */

void pall(stack_t **stack, unsigned int linen __attribute__((unused)))
{
	print_stack(*stack);
}
