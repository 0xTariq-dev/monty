#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: A pointer to the list.
 *
 * Return: Nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	if (tmp != NULL)
	{
		free_stack(tmp->next);
		free(tmp);
	}
}
