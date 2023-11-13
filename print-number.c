#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @pchar: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, pchar_t *pchar)
{
	unsigned int i = _strlen(str);
	int neg = (!pchar->unsign && *str == '-');

	if (!pchar->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (pchar->precision != UINT_MAX)
		while (i++ < pchar->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!pchar->minus_flag)
		return (print_number_right_shift(str, pchar));
	else
		return (print_number_left_shift(str, pchar));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @pchar: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, pchar_t *pchar)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (pchar->zero_flag && !pchar->minus_flag)
		pad_char = '0';
	neg = neg2 = (!pchar->unsign && *str == '-');
	if (neg && i < pchar->width && pad_char == '0' && !pchar->minus_flag)
		str++;
	else
		neg = 0;
	if ((pchar->plus_flag && !neg2) ||
		(!pchar->plus_flag && pchar->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (pchar->plus_flag && !neg2 && pad_char == '0' && !pchar->unsign)
		n += _putchar('+');
	else if (!pchar->plus_flag && pchar->space_flag && !neg2 &&
		!pchar->unsign && pchar->zero_flag)
		n += _putchar(' ');
	while (i++ < pchar->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (pchar->plus_flag && !neg2 && pad_char == ' ' && !pchar->unsign)
		n += _putchar('+');
	else if (!pchar->plus_flag && pchar->space_flag && !neg2 &&
		!pchar->unsign && !pchar->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @pchar: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, pchar_t *pchar)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (pchar->zero_flag && !pchar->minus_flag)
		pad_char = '0';
	neg = neg2 = (!pchar->unsign && *str == '-');
	if (neg && i < pchar->width && pad_char == '0' && !pchar->minus_flag)
		str++;
	else
		neg = 0;

	if (pchar->plus_flag && !neg2 && !pchar->unsign)
		n += _putchar('+'), i++;
	else if (pchar->space_flag && !neg2 && !pchar->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < pchar->width)
		n += _putchar(pad_char);
	return (n);
}
