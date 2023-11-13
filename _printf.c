#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	pchar_t  pchar = PCHAR_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_pchar(&pchar, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &pchar)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &pchar, ap);
		p = get_precision(p, &p_char, ap);
		if (get_modifier(p, &pchar))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
				pchar.l_modifier ||p_char.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &pchar);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
