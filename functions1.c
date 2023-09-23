#include "monty.h"

/**
 * push - Add element to the stack.
 * @stack: A pointer to the list.
 * @n: The value to add to the list.
 *
 */
void push(stack_t **stack, unsigned int line)
{
	stack_t *new;
	(void)line;

	new = new_element(data);
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - Prints all the elements of a stack.
 * @stack: The stack to print.
 * @n: Count.
 *
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *current = NULL;
	(void)line;

	current = *stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * new_element - Add new element to the stack.
 * @element: The data.
 *
 * Return: new node
 */
stack_t *new_element(int element)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = element;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * pint - a function that prints the value at the
 * top of the stack.
 * @stack: the stack.
 * @line_number: the number of line in the
 * Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
