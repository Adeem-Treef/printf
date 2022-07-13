#include "main.h"

/**
 * parse_format - Receives formatted string with or without specifiers.
 * @format: String containing characters and specifiers of characters
 * to be printed.
 * @f_list: List of all functions to handle specifiers.
 * @args: list of argumentents to be printed.
 * Return: Count of printed characters.
 */
int parse_format(const char *format, convert_t *f_list, va_list args)
{
	int i, j, r_val, c;

	c = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/*Iterates through f_list matching function*/
			for (j = 0; f_list[j].spc != NULL; j++)
			{
				if (format[i + 1] == f_list[j].spc[0])
				{
					r_val = f_list[j].f(args);
					if (r_val == -1)
						return (-1);
					c += r_val;
					break;
				}
			}
			if (f_list[j].spc == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					c += 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			c++;
		}
	}
	return (c);
}
