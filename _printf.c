#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int buffer_index = 0;
int printed_chars = 0;
int intitial_value;
int flags;
int width;
int precision;
int printed;
int size;
va_list args;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(args, format);
for (intitial_value = 0; format[intitial_value] != '\0'; intitial_value++)
{
if (format[intitial_value] != '%')
{
buffer[buffer_index++] = format[intitial_value];
if (buffer_index == BUFF_SIZE)
{
print_buffer(buffer, &buffer_index);
}
printed_chars++;
}
else
{
print_buffer(buffer, &buffer_index);
intitial_value++;
flags = myFlags(format, &intitial_value);
width = myWidth(format, &intitial_value, args);
precision = myPrecision(format, &intitial_value, args);
size = mySize(format, &intitial_value);
printed = handle_print(format, &intitial_value, args, buffer,
flags, width, precision, size);
if (printed == -1)
{
va_end(args);
return (-1);
}
printed_chars += printed;
}
}
print_buffer(buffer, &buffer_index);
va_end(args);
return (printed_chars);
}
/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buffer_index: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buffer_index)
{
int i;
for (i = 0; i < *buffer_index; i++)
{
write(1, &buffer[i], 1);
}
*buffer_index = 0;
}
