#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
* _printf - Custom printf function to output formatted data
* @format: format string containing the specifiers
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
int count = 0;
int t;
int u;
char temp;
char *str;
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
temp = (char)va_arg(args, int);
count += write(1, &temp, 1);
break;
case 's':
{
str = va_arg(args, char*);
if (str == NULL)
str = "(null)";
for (u = 0; str[u]; u++)
count += write(1, &str[u], 1);
}
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
