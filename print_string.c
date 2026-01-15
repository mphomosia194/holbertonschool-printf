#include "main.h"

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s;
	int i = 0;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}

	return (i);
}
