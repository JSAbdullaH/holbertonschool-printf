#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string with directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args; // Variable argument list
	int i = 0;
	int count = 0;

	if (!format) // Check for NULL format string
		return (-1);

	va_start(args, format);

	while (format[i]) // Loop through the format string
	{
		if (format[i] != '%') // Handle regular characters
		{
			count += _putchar(format[i]);
		}
		else // Handle format specifier
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			count += handle_specifier(format[i], args);
		}
		i++;
	}

	va_end(args); // Clean up variable argument list
	return (count);
}