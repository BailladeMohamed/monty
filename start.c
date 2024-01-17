#include "monty.h"

/**
 * main - Entry point
 * @argc: amount of arguments passed to our program
 * @argv: list of arguments passed to our program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *f;
	size_t len = 0;
	char *buf = NULL;
	char *str = NULL;
	stack_t *s = NULL;
	unsigned int cnt = 1;
	int status = 0; /* Local variable to replace global variable */

	global.data = 1;
	if (argc != 2)
		erusage();
	f = fopen(argv[1], "r");
	if (!f)
		fileer(argv[1]);
	while ((getline(&buf, &len, f)) != (-1))
	{
		if (status)
			break;
		if (*buf == '\n')
		{
			cnt++;
			continue;
		}
		str = strtok(buf, " \t\n");
		if (!str || *str == '#')
		{
			cnt++;
			continue;
		}
		global.arg = strtok(NULL, " \t\n");
		op_code(&s, str, cnt);
		cnt++;
	}
	free(buf);
	freestk(s);
	fclose(f);
	exit(EXIT_SUCCESS);
}

/**
 * fileer - prints file error message and exits
 * @av: argv given by main()
 *
 * Return: None
 */
void fileer(char *av)
{
	fprintf(stderr, "Error: Can't open file %s\n", av);
	exit(EXIT_FAILURE);
}

/**
 * erusage - prints usage message and exits
 *
 * Return: None
 */
void erusage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
