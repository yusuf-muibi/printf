#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
* print_char - Prints a character
* @args: A list of variadic arguments
* Return: The number of characters printed
*/
static int print_char(va_list args)
{
char c = (char)va_arg(args, int);
return (write(1, &c, 1));
}
/**
* print_string - Prints a string
* @args: A list of variadic arguments
* Return: The number of characters printed
*/
static int print_string(va_list args)
{
char *str;
int count = 0;
int t;
str = va_arg(args, char*);
if (str == NULL)
str = "(null)";
for (t = 0; str[t]; t++)
count += write(1, &str[t], 1);
return (count);
}
/**
* _printf - Custom printf function to output formatted data
* @format: The format string containing specifiers
* Return: The number of characters printed
*/
int _printf(const char *format, ...)
{
int count = 0;
int t;
va_list args;
va_start(args, format);
for (t = 0; format && format[t]; t++)
{
if (format[t] == '%' && format[t + 1])
{
t++;
switch (format[t])
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
count += write(1, &format[t], 1);
break;
default:
count += write(1, &format[t - 1], 1) + write(1, &format[t], 1);
}
}
else
{
count += write(1, &format[t], 1);
}
}
va_end(args);
return (count);
}
