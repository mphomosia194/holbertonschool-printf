#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed = 0, j;
	spec_t specs[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'d', print_int},
	{'i', print_int},
	{0, NULL}
};


	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed++;
			i++;
			continue;
		}

		i++;
		if (format[i] == '\0')
		{
			va_end(args);
			return (-1);
		}

		j = 0;
		while (specs[j].spec)
		{
			if (format[i] == specs[j].spec)
			{
				printed += specs[j].f(args);
				break;
			}
			j++;
		}

		if (!specs[j].spec)
		{
			write(1, "%", 1);
			write(1, &format[i], 1);
			printed += 2;
		}
		i++;
	}

	va_end(args);
	return (printed);
}
