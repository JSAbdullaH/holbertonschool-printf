#include "main.h"

/* Afnan TODO - print_char */
/
 * print_char - prints a character
 * @args: va_list containing the character
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
  char c;

  c = va_arg(args, int);
  return (write(1, &c, 1));
}

/* Afnan TODO - print_string */
/
 * print_string - prints a string
 * @args: va_list containing the string
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
  char *str;
  int i;

  str = va_arg(args, char *);
  if (str == NULL)
    str = "(null)";
  for (i = 0; str[i] != '\0'; i++)
    write(1, &str[i], 1);
  return (i);
}

/* Afnan TODO - print_percent */
/
 * print_percent - prints a percent sign
 * @args: va_list (unused)
 *
 * Return: 1
 */
int print_percent(va_list args)
{
  (void)args;
  return (write(1, "%", 1));
}

/* Afnan TODO - get_func */
/
 * get_func - matches format specifier to handler function
 * @s: the format specifier character
 *
 * Return: pointer to the corresponding function, or NULL
 */
int (*get_func(char s))(va_list)
{
  spec_t specs[] = {
    {'c', print_char},
    {'s', print_string},
    {'%', print_percent},
    {0, NULL}
  };
  int i;

  for (i = 0; specs[i].func != NULL; i++)
  {
    if (specs[i].specifier == s)
      return (specs[i].func);
  }
  return (NULL);
}
