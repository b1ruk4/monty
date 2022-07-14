#include "monty.h"

/**
 * run_monty - Runs the opcode command.
 *
 * @buffer: The line instruction read from the given file.
 * @line_number: The line number.
 *
 */

void run_monty(char *buffer, unsigned int line_number)
{
	char *cmd, *value;

	void (*f)(stack_t**, unsigned int);

	cmd = strtok(buffer, " \r\t\n");

	if (cmd && cmd[0] != '#')
	{
		f = get_func(cmd);

		if (f != NULL)
		{
			if (strcmp(cmd, "push") == 0)
				value = strtok(NULL, " \r\t\n");
			f(&h, line_number);
		}
		else
		{
			error_op(line_number, cmd);
			if (buffer)
				free(buffer);
			if (h)
				free_dlistint(h);
			exit(EXIT_FAILURE);
		}
	}
}
