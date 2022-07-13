#include "main.h"

/**
 * _printf - prints a formated string
 * @format: string containing characters to be printed and their format
 * Return: length of string printed
 */
int _printf(const char *format, ...)
{
	int num_p;
	convert_t func_l[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_x},
		{"X", print_X},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	num_p = parse_format(format, func_l, args);
	va_end(args);
	return (num_p);
}
