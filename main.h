#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

/**
 * struct convert - format types
 * @spc: specification
 * @f: function pointer
 */
typedef struct convert
{
	char *spc;
	int (*f)(va_list args);
} convert_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args_l);
int print_string(va_list args_l);
int print_percent(va_list args_l);
int print_integer(va_list args_l);
int print_unsigned_integer(va_list args_l);
int print_number(va_list args_l);
int print_unsgined_number(unsigned int n);
int print_binary(va_list args_l);
int print_octal(va_list args_l);
int print_hex_x(va_list args_l);
int print_hex_X(va_list args_l);
int parse_format(const char *format, convert_t f_list[], va_list args);

#endif
