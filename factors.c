#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Factorize a given number into two smaller numbers.
 * @number: The number to factorize.
 */
void factorize(int number)
{
	int i;

	for (i = 2; i <= number; i++)
	{
		if (number % i == 0)
		{
			printf("%d=%d*%d\n", number, number / i, i);
			break;
		}
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	ssize_t line;
	size_t count;
	char *buf;
	int number;
	FILE *file;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line = getline(&buf, &count, file)) != - 1)
	{
		number = atoi(buf);
		factorize(number);
	}
	free(buf);
	fclose(file);
	return (0);
}
