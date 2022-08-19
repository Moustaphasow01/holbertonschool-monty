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
	char *bcode = strtok(current_line, " ");

	if (strcmp(bcode, "push") != 0)
	{
		//testdevMoustapha
        dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, bcode);
		return;
	}

	bcode = strtok(NULL, " ");
	for (i = 0; bcode[i]; i++)
	{
		if (isalpha(bcode[i]) != 0)
		{
		//testdevMoustapha2
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(bcode);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		//testdevMoustapha3
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
		return;
	}

	new->n = num;
	new->next = *stack;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall- all prints all the values on the stack
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	char *bcode = strtok(current_line, " ");

	if (strncmp(bcode, "pall", 4) != 0)
	{
		//testdevMoustapha4
		dprintf(2, "L%u: unknown instruction %s\n", line_number, bcode);
		return;
	}

	h = *stack;

	while (h)
	{
		printf("%d\n", h->n);
		//testdevMoustapha5
		h = h->next;
	}
}