#include "../main.h"

/**
 * test_print_char - test printing characters
 * Return: 0 always
 */
int test_print_char(void)
{
	int lowercase_char = 'a';
	int uppercase_char = 'A';
	int symbol = '-';
	int special_character = '\n';

	_printf("Print a lowercase character:");
	_printf("%c", lowercase_char);
	_printf("\n");
	_printf("Print a lowercase character:");
	_printf("%c", uppercase_char);
	_printf("\n");
	_printf("Print a symbol:");
	_printf("%c", symbol);
	_printf("\n");
	_printf("print a special character");
	_printf("%c", special_character);
	return (0);
}
