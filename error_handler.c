#include "monty.h"

/**
  * handle_error - Manages the printing of interpreter errors
  * @errno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  * @buff: The reserved error line buffer
  *
  * Return: Nothing
  */
void handle_error(int errno, char *opcode, unsigned int line, char *buff)
{
	if (errno >= 100 && errno < 200)
		handle_cerror(errno, opcode, line);
	else if (errno >= 200 && errno <= 210)
		handle_uerror(errno, line);
	else if (errno >= 211 && errno <= 220)
		handle_more_uerror(errno, line);
	else
		return;

	frees_stack();

	if (buff)
		free(buff);

	exit(EXIT_FAILURE);
}
