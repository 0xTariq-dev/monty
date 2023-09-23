#include "monty.h"

/**
 * nop - useless func
 * @stack: the stack.
 * @n: the number of the line.
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * _div - Devides the second top element by the top element of the stack.
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void _div(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (line < 3)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n /= (*stack)->n;
	pop(stack, line);
}

/**
 * mul - multiblies the second top element with the top element of the stack.
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void mul(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (line < 3)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n *= (*stack)->n;
	pop(stack, line);
}

/**
 * mod - computes the rest of the division of the second top element of
 *		the stack by the top element of the stack.
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void mod(stack_t **stack, unsigned int line)
{
	stack_t *last;

	if (line < 3)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	last = (*stack)->next;
	last->n %= (*stack)->n;
	pop(stack, line);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: A pointer to the stack.
 * @n: The line number.
 */
void pchar(stack_t **stack, unsigned int line)
{
	int x;

	if (line < 2)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;

	if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
		printf("%c\n", (char)x);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
}
