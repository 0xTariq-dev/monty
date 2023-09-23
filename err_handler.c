#include "monty.h"

/**
 * err_push - Show error message if push failed.
 * @mon: Instructions file.
 * @line: Instructions buffer.
 * @stack: Data structure (stack or queue);
 * @count: line number.
 */
void err_push(FILE *mon, char *line, stack_t *stack, int count)
{
	fprintf(stderr, "L%u: usage: push integer\n", count);
	fclose(mon);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * inv_inst - Show error message if invalid instruction is passed.
 * @mon: Instructions file.
 * @line: Instructions buffer.
 * @stack: Data structure (stack or queue).
 * @count: line number.
 * @element: number.
 */
void inv_inst(FILE *mon, char *line, stack_t *stack, char *argument, int count)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", count, argument);
	fclose(mon);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
