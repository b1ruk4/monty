#include "monty.h"
/**
 * main - Entry point for the monty Interpreter.
 * @ac: The number of arguments passed to the program.
 * @av: The A pointer to an array of characters.
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */

int main(int ac, char **av)
{
	size_t status;
	char *buffer = NULL;
	unsigned int line_number = 0;
	stack_t *h;
	FILE *file;
	char *value;
	int mode;
	char *cmd;

	h = NULL;
	value = NULL;
	file = NULL;
	mode = 0;
	cmd = NULL;

	if (ac != 2)
	{
		error_ac();
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		error_fopen(av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &status, file) != EOF)
	{
		line_number++;
		if (buffer[0] != '\n')
			run_monty(buffer, line_number);
	}

	if (buffer)
		free(buffer);
	if (h)
		free_dlistint(h);

	fclose(file);
	return (EXIT_SUCCESS);
}
