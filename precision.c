#include "main.h"
#include <ctype.h>
/**
* myPrecision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
* @list: list of arguments.
* Return: Precision.
*/
int myPrecision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;
precision = 0;
if (format[curr_i] != '.')
return (precision);
while (format[curr_i] != '\0')
{
if (isdigit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
{
break;
}
curr_i++;
}
*i = curr_i - 1;
return (precision);
}
