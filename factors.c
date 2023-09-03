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
		while (number % i == 0)
		{
			printf("%d=%d*%d\n", number, i, number / i);
			return;
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
	char line[20];
	int number;
	FILE *file;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fgets(line, sizeof(line), file))
	{
		number = atoi(line);
		factorize(number);
	}

	fclose(file);
	return (0);
}
