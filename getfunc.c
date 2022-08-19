#include "monty.h"

/**
 * getfunc - selects the right function
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL 
 */
void (*getfunc(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push},
		{"pall", pall}
        {"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};

	int codes = 7, i;

	for (i = 0; i < codes; i++)
	{
		if (strcmp(func_arr[i].opcode, parsed[0] )== 0)
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
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	
		for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
		//testdevMoustapha2
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
            exit(EXIT_FAILURE);
		}
	}

    num = atoi(data.words[1]);
	new = add_dnodeint(stack, num);
	if (!new)
	{
		//testdevMoustapha3
		dprintf(STDERR_FILENO, MALLOC_FAIL);
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