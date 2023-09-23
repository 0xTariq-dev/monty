#include "monty.h"

/**
 * pop - delete the element at the top of stack.
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	last = *stack;
	*stack = (*stack)->next;
	free(last);
}

/**
 * add - a function that adds the top two elements of the stack.
 * @stack: the stack.
 * @line_number: the number of the line.
 */
void add(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line);
}

/**
 * swap - swap top two elements of the stack.
 * @stack: the stack.
 * @n: the number of the line.
 */
void swap(stack_t **stack, unsigned int line)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * sub - Subs the top two elements of the stack
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void sub(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (line < 3)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n -= (*stack)->n;
	pop(stack, line);
}

/**
 * pstr - prints the string starting at the top of the stack,
 *		followed by a new line.
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void pstr(stack_t **stack, unsigned int line)
{
	stack_t *h = *stack;
	(void)line;

	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;

		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
