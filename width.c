#include "main.h"
/**
* myWidth - Calculates the width for printing
* @format: Formatted string in which to print the arguments.
* @i: List of arguments to be printed.
* @list: list of arguments.
* Return: width.
*/
int myWidth(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int width = 0;
while (format[curr_i] != '\0')
{
if (isdigit(format[curr_i]))
{
width *= 10;
width += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
width = va_arg(list, int);
break;
}
else
{
break;
}
curr_i++;
}
*i = curr_i - 1;
return (width);
}
