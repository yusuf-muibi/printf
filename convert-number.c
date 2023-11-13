#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @pchar: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, pchar_t *pchar)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (pchar->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pchar->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pchar);
	if (pchar->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	pchar->unsign = 1;
	return (c += print_number(str, pchar));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @pchar: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, pchar_t *pchar)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (pchar->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pchar->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, pchar);
	if (pchar->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	pchar->unsign = 1;
	return (c += print_number(str, pchar));
}
/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @pchar: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, pchar_t *pchar)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, pchar);
	int c = 0;

	if (pchar->hashtag_flag && n)
		*--str = '0';
	pchar->unsign = 1;
	return (c += print_number(str, pchar));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @pchar: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, pchar_t *pchar)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (pchar->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pchar->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, pchar);

	if (pchar->hashtag_flag && l)
		*--str = '0';
	pchar->unsign = 1;
	return (c += print_number(str, pchar));
}
