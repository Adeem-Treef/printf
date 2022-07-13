#include "main.h"

/**
 * replace_special_char - replases all special characters
 * @c: character
 * Return: int
 */
int replace_special_char(char c)
{
	int l = base_len(c, 16);

	_putchar('\\');
	_putchar('x');
	if (l == 1)
	{
		_putchar('0');
		_print_hex(c, 1);
	}
	else
	{
		_print_hex(c, 1);
	}
	return (4);
}

/**
 * print_custom_string - Prints a string
 * @args_l: list of arguments
 * Return: Count of printed characters
 */
int print_custom_string(va_list args_l)
{
	int i;
	char *s;
	
	s = va_arg(args_l, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		if ((s[i] > 0 && s[i] <32) || s[i] >= 127)
		{
			replace_special_char(s[i]);
		}
		else
		{
			_putchar(s[i]);
		}
	return (i);
}
