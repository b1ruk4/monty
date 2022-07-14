#include "monty.h"

/**
 * stack_queue - Sets the format of the data to stack and queue.
 *
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: The line number
 *
 */

void stack_queue(stack_t **stack, unsigned int line_number)
{
	int mode;

	(void)stack;
	(void)line_number;

	if (strcmp(cmd, "queue") == 0)
		mode = 1;
	else
		mode = 0;
}
