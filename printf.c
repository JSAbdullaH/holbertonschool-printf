#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string with directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

    /* Loop through the format string  ToDo : Afnan*/

	return (count);
}