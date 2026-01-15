#include "main.h"

/**
 * print_int_recursive - prints an unsigned integer recursively
 * @n: number to print
 *
 * Return: number of characters printed
 */
static int print_int_recursive(unsigned int n)
{
	char c;
	int count = 0;

	if (n / 10)
		count += print_int_recursive(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

/**
 * print_int - prints an integer
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n;
	unsigned int num;
	int count = 0;

	n = va_arg(args, int);

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	count += print_int_recursive(num);
	return (count);
}
