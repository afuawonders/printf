#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1
/**
* struct fmt - Struct op
*
* @fmt: The format.
* @fn: The function associated.
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};
/**
* typedef struct fmt fmt_t - Struct op
*
* @fmt: The format.
* @fm_t: The function associated.
*/
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int formatTochar(va_list types, char buffer[],
int flags, int width, int precision, int size);
int formatTostring(va_list types, char buffer[],
int flags, int width, int precision, int size);
int formatToPercentage(va_list types, char buffer[],
int flags, int width, int precision, int size);
int converToint(va_list types, char buffer[],
int flags, int width, int precision, int size);
int handleBinary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int convertToUnsign(va_list types, char buffer[],
int flags, int width, int precision, int size);
int formatOctal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int convertToHexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int formatToUpperHex(va_list types, char buffer[],
int flags, int width, int precision, int size);
int hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int handleNonPrintable(va_list types, char buffer[],
int flags, int width, int precision, int size);
int handlePointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
int myFlags(const char *format, int *i);
int myWidth(const char *format, int *i, va_list list);
int myPrecision(const char *format, int *i, va_list list);
int mySize(const char *format, int *i);
int hanleReverse(va_list types, char buffer[],
int flags, int width, int precision, int size);
int handleR13(va_list types, char buffer[],
int flags, int width, int precision, int size);
int handleChar(char c, char buffer[],
int flags, int width, int precision, int size);
int handleNumber(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int writeUsigned(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);
int is_printable(char);
int hexadecimal(char, char[], int);
int is_digit(char);
long int convertNumberWithSize(long int num, int size);
long int convertUnsignedSizeNumber(unsigned long int num, int size);
#endif /* MAIN_H */
