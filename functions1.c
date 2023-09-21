#include "monty.h"

int data;

/**
 * new_element - Add new element to the stack.
 * @element: The data.
 *
 * Return: The new element.
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
 * push - Add element to the stack.
 * @head: A pointer to the list.
 * @n: The value to add to the list.
 *
 * Return: The Address of the new element
 */
void push(stack_t **stack, unsigned int n)
{
        stack_t *new;
        (void)n;

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
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
