#include <stdio.h>

/*
 * Main - argv
 * Start from argv[1] (the first argument) and
 * continue until a NULL pointer is encountered.
 */

int main(int argc, char **argv)
{
	
	int i = 1;

	while (argv[i] != NULL)
	{
		printf("Argument %d: %s\n", i, argv[i]);
		i++;
	}

	return 0;
}

