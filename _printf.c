#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, printed = 0, j;
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed++;
			continue;
		}

		i++;
		for (j = 0; specs[j].spec; j++)
		{
			if (format[i] == specs[j].spec)
			{
				printed += specs[j].f(args);
				break;
			}
		}

		if (!specs[j].spec)
		{
			write(1, "%", 1);
			write(1, &format[i], 1);
			printed += 2;
		}
	}

	va_end(args);
	return (printed);
}
