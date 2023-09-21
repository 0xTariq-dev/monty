#include "monty.h"

glob_t global = {NULL, NULL};

/**
 * main - Monty interpreter main function that get instructions from monty
 *		pytecode file and excute it on a stack.
 *
 * @argc: Count of arguments passed to the program.
 * @argv: List of the arguments passed.
 *
 * Return: SUCCESS if instruction is done Or FAILURE if:
 *	1. The user does not give any file or more than one argument.
 *	2. It’s not possible to open the file.
 *	3. If the file contains an invalid instruction.
 *	4. If you can’t malloc anymore.
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		file_handler(argv[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

/**
 * file_handler - Read the file and get the instructions.
 * @args: Arguments passed.
 *
 * Return: Nothing.
 */
void file_handler(char *argv)
{
	int count = 0, res = 0;
	char *arguments = NULL, *element = NULL, *delims = " \t\r\n";
	stack_t *stack = NULL;
	size_t len = 0;

	global.m_code = fopen(argv, "r");
	if (!global.m_code)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(&global.line, &len, global.m_code) != -1)
		{
			count++;
			arguments = strtok(global.line, delims);
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			else if (*arguments == '#')
				continue;
			element = strtok(NULL, delims);
			res = exec_op(&stack, argv, element, count);
			if (res == 1)
				err_push(global.m_code, global.line, stack, count);
			else if (res == 2)
				inv_inst(global.m_code, global.line, stack, argv, count);
			free(global.line);
			free_stack(stack);
			fclose(global.m_code);
		}
	}
}

/**
 * exec_op - Execute operation on a stack.
 * @stack: The stack.
 * @argument: The operation name.
 * @element: An element.
 * @n: Line number.
 */
int exec_op(stack_t **stack, char *argument, char *element, int n)
{
	int x = 0;
	instruction_t op[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};

	while (op[x].opcode)
	{
		if (!strcmp(argument, op[x].opcode))
		{
			if (!strcmp(argument, "push"))
			{
				if (isdigit(element) == 1)
					data = atoi(element);
				else
					exit(1);
			}
			op[x].f(stack, (unsigned int)n);
			break;
		}
		x++;
	}
	if (!op[x].opcode)
		exit(2);

	exit(0);
}
				
