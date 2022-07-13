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
* _print_hex - function that prints an unsigned int in hexadecimal
* @n: unsigned to be printed
* @c: case of printing (0 = lower, 1 = upper)
* Return: size of the character written
*/
int _print_hex(unsigned int n, unsigned int c)
{
	unsigned int length = 0, power = 1, k, digit, number;
	int count = 0;
	char diff;

	if (n != 0)
	{
		number = n;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (number != 0)
		{
			number /= 16;
			length++;
		}
		for (k = 1; k <= length - 1; k++)
		{
			power *= 16;
		}
		for (k = 1; k <= length; k++)
		{
			digit = n / power;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * power;
			power /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/**
* print_x - takes an unsigned int an prints it in lowercase hex
* @args_l: unsigned int to print
* Return: size of the character written
*/
int print_x(va_list args_l)
{
	return (_print_hex(va_arg(args_l, unsigned int), 0));
}

/**
* print_X - takes an unsigned int an prints it in uppercase hex
* @args_l: unsigned int to print
* Return: size of the character written
*/
int print_X(va_list args_l)
{
	return (_print_hex(va_arg(args_l, unsigned int), 1));
}
