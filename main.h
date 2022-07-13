#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
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
int print_x(va_list args_l);
int print_X(va_list args_l);
int parse_format(const char *format, convert_t f_list[], va_list args);

/* ====TESTS==== */
int test_print_char(void);

/* ====UTILS==== */
unsigned int base_len(unsigned int num, int base);
char *rev_str(char *);
char *_memcpy(char *, char *, unsigned int );
int hex_check(int num, char x);

#endif
