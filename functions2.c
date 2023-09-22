#include "monty.h"

/**
 * pop - delete the element at the top of stack.
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void pop(stack_t **stack, unsigned int n)
{
	stack_t *last;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", n);
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
 */
void add(stack_t **stack, unsigned int n)
{
	stack_t *last;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n += (*stack)->n;
	pop(stack, n);
}
/**
 * swap - swap top two elements of the stack.
 * @stack: the stack.
 * @n: the number of the line.
 */
void swap(stack_t **stack, unsigned int n)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
