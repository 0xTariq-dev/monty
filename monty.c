/*
 * Author: 0xTariq-dev, HeshamOrabi
 * File: monty.c
 */

#include "monty.h"

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
	FILE *m_code = fopen(argv[1], "r");
	/*stack_t *head;*/
	/*instruction_t *cmd;*/
	int tkn_count = 0;
	char *token, *line = NULL, *rest, *data = NULL, *command, *next_token;
	ssize_t read;
	size_t len = 0;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (m_code == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		goto cleanup;
		exit(EXIT_FAILURE);
	}
	/*head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}*/

	while ((read = getline(&line, &len, m_code)) != -1)
	{
		rest = malloc(strlen(line) + 1);
		strcpy(rest, line);
		token = strtok_r(rest, " \n", &next_token);
            	tkn_count += 1;
		if (tkn_count == 1)
		{
			/*cmd = malloc(sizeof(instruction_t));
			if (cmd == NULL)
			{
   				fprintf(stderr, "Error: malloc failed\n");
		    		exit(EXIT_FAILURE);
			}*/
			command = malloc(strlen(token) + 1);
			strcpy(command, token);
			printf("commad: %s ", command);
		}
		token = strtok_r(next_token, " \n", &next_token);
		if (token != NULL)
		{
            		tkn_count += 1;
			if (tkn_count == 2)
			{
				data = malloc(strlen(token) + 1);
				strcpy(data, token);
				printf("data: %s\n", data);
			}
		}
		/*free(cmd->opcode);
		free(cmd);
		cmd = NULL;*/
		if (tkn_count == 2)
		{
			free(data);
			free(command);
			data = NULL;
		}
            	tkn_count = 0;
		free(rest);
	}
cleanup:
	free(line);
	fclose(m_code);
	exit(EXIT_SUCCESS);
}
