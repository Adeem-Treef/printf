#include "main.h"

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list args)
{
	int n, d, l;
	unsigned int num;

	n  = va_arg(args, int);
	d = 1;
	l = 0;

	if (n < 0)
	{
		l += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	while (num / d > 9)
		d *= 10;

	while (d != 0)
	{
		l += _putchar('0' + num / d);
		num %= d;
		d /= 10;
	}

	return (l);
}

/**
 * print_unsgined_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unsgined_number(unsigned int n)
{
	int d = 1, l = 0;
	unsigned int num;

	num = n;

	while (num / d > 9)
		d *= 10;

	while (d != 0)
	{
		l += _putchar('0' + num / d);
		num %= d;
		d /= 10;
	}

	return (l);
}
