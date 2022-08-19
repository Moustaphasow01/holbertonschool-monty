#include "monty.h"

/**
 * getfunc - selects the right function
 * @line: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL 
 */
void (*getfunc(char *line))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push},
		{"pall", pall}
	};

	int codes = 2, i;

	for (i = 0; i < codes; i++)
	{
		if (strncmp(func_arr[i].opcode, line, 4) == 0)
			return (func_arr[i].f);
	}
	return (NULL);
}

/**
 * push -  pushes an element to the stack.
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;
    if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	
		for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
		//testdevMoustapha2
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			free_all(1);
            exit(EXIT_FAILURE);
		}
	}

    num = atoi(data.words[1]);
	new = add_dnodeint(stack, num);
	if (!new)
	{
		//testdevMoustapha3
        dprintf(2, "Error: malloc failed\n");
		free_all(1);
		exit(EXIT_FAILURE);
	}

	
}
/**
 * pall- all prints all the values on the stack
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}