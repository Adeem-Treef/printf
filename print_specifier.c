#include "main.h"

/**
 * print_char - Prints a ciharacter
 * @args_l: argument list
 * Return: count of printed characters
 */
int print_char(va_list args_l)
{
	_putchar(va_arg(args_l, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @args_l: list of arguments
 * Return: Count of printed characters
 */
int print_string(va_list args_l)
{
	int i;
	char *s;

	s = va_arg(args_l, char *);
	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @args_l: argument list (unused)
 * Return: Count of printed characters.
 */
int print_percent(__attribute__((unused))va_list args_l)
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @args_l: argument list
 * Return: Count of printed characters.
 */
int print_integer(va_list args_l)
{
	int l;

	l = print_number(args_l);
	return (l);
}

/**
 * print_unsigned_integer - Prints unsigned integers
 * @args_l: argument list
 * Return: count of characters  printed
 */
int print_unsigned_integer(va_list args_l)
{
	unsigned int n;

	n = va_arg(args_l, unsigned int);

	if (n == 0)
		return (print_unsgined_number(n));

	if (n < 1)
		return (-1);
	return (print_unsgined_number(n));
}
