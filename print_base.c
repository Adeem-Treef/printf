#include "main.h"

/**
 * print_binary - prints an integer in base 2
 * @args_l: list of arguments
 * Return: count of characters printed
 */
int print_binary(va_list args_l)
{
	unsigned int n;
	int l, i, j;
	char *p, *rev_s;

	n = va_arg(args_l, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	l = base_len(n, 2);
	p = malloc(sizeof(char) * l + 1);
	if (p == NULL)
		return (-1);
	i = 0;
	while (n > 0)
	{
		p[i] = 48 + n % 2;
		n /= 2;
		i++;
	}
	p[i] = '\0';
	rev_s = rev_str(p);
	if (rev_s == NULL)
		return (-1);

	j = 0;
	while (rev_s[j] != '\0')
	{
		_putchar(rev_s[j]);
		j++;
	}
	free(p);
	free(rev_s);
	return (l);
}


/**
 * print_octal - Prints the numeric representation of a number in octal base
 * @args_l: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_octal(va_list args_l)
{
	unsigned int n;
	int l, j;
	char *p, *rev_s;

	n = va_arg(args_l, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	l = base_len(n, 8);

	p = malloc(sizeof(char) * l + 1);
	if (p == NULL)
		return (-1);
	for (l = 0; n > 0; l++)
	{
		p[l] = (n % 8) + 48;
		n /= 8;
	}
	p[l] = '\0';
	rev_s = rev_str(p);
	if (rev_s == NULL)
		return (-1);

	j = 0;
	while (rev_s[j] != '\0')
	{
		_putchar(rev_s[j]);
		j++;
	}
	free(p);
	free(rev_s);
	return (l);
}

/**
 * print_hex_x - Prints a representation of a decimal number on base16 lowercase
 * @ars_l: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex_x(va_list args_l)
{
	unsigned int n;
	int i, l, rem_num;
	char *p, *rev_s;

	n = va_arg(args_l, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	l = base_len(n, 16);
	p = malloc(sizeof(char) * l + 1);
	if (p == NULL)
		return (-1);
	for (l = 0; n > 0; l++)
	{
		rem_num = n % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			p[l] = rem_num;
		}
		else
			p[l] = rem_num + 48;
		n /= 16;
	}
	p[l] = '\0';
	rev_s = rev_str(p);
	if (rev_s == NULL)
		return (-1);
	for (i = 0; p[i] != '\0'; i++)
		_putchar(p[i]);
	free(p);
	free(rev_s);
	return (l);
}


/**
 * print_hex_X - Prints a representation of a decimal number on base16 Uppercase
 * @args_l: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex_X(va_list args_l)
{
	unsigned int n;
	int i, l, rem_num;
	char *p, *rev_s;

	n = va_arg(args_l, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	l = base_len(n, 16);
	p = malloc(sizeof(char) * l + 1);
	if (p == NULL)
		return (-1);
	for (l = 0; n > 0; l++)
	{
		rem_num = n % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			p[l] = rem_num;
		}
		else
			p[l] = rem_num + 48;
		n /= 16;
	}
	p[l] = '\0';
	rev_s = rev_str(p);
	if (rev_s == NULL)
		return (-1);
	for (i = 0; p[i] != '\0'; i++)
		_putchar(p[i]);
	free(p);
	free(rev_s);
	return (l);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
