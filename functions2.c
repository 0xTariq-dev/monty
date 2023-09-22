#include "monty.h"

/**
 * pop - delete the element at the top of stack.
 * @stack: A pointer to the stack.
 * @n: The line number.
 *
 * Return: FAILURE if the stack is empty.
 */
void pop(stack_t **stack, unsigned int n)
{
	stack_t *last;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}

	last = *stack;
	*stack = (*stack)->next;
	free(last);
}

/**
 * add - Adds the two ele.
 * @stack: A pointer to the stack.
 * @n: The line number.
 *
 * Return: FAILURE if the stack contains less than two elements.
 */
void add(stack_t **stack, unsigned int n)
{
	stack_t *last;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n += (*stack)->n;
	pop(stack, n);
}
