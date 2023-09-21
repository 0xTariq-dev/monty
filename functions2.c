#include "monty.h"

/**
 * pop - delete the element at the top of stack.
 * @stack: A pointer to the list.
 * @index: The index to delete the node at.
 *
 * Return: 1 on success or -1 on fail.
 */
void pop(stack_t **stack, unsigned int n)
{
	stack_t *last;
	(void)n;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pop an empty stack");
		exit(EXIT_FAILURE);
	}

	last = *stack;
	*stack = (*stack)->next;
	free(last);
}
