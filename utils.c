#include "main.h"

/**
 * base_len - calculates the lenght of num in base
 * @num: number to be converted
 * @base: base
 * Return: lenght
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	i = 0;
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

/**
 * rev_str - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */
char *rev_str(char *s)
{
	int l;
	int h;
	char tmp;
	char *dest;

	l = 0;
	while (s[l] != '\0')
		l++;

	dest = malloc(sizeof(char) * l + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, l);
	for (h = 0; h < l; h++, l--)
	{
		tmp = dest[l - 1];
		dest[l - 1] = dest[h];
		dest[h] = tmp;
	}
	return (dest);
}

/**
 * _memcpy - copy memory area
 * @dest: Destination for copying
 * @src: Source to copy from
 * @n: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
