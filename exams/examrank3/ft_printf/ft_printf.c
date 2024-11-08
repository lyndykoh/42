/*
Assignment: ft_printf
Expected files: ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end 
----------------------------------------------------------------------------

Prototype: int ft_printf(const char *, ...);
Write a function named ft_printf that will mimic the real printf but only manage the following conversions:
1. s(string)
2. d (decimal)
3. x (lowercase hexadecimal)

Output examples:

call: ft_printf("%s\n", "toto")
out: toto$

call: ft_printf("Magic %s is %d", "number", 42)
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42)
out: Hexadecimal for 42 is 2a$
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putstr(char *str)
{
    int i = 0;
    if (str == NULL)
        str = "(null)";
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    int count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n > 9)
        count += ft_putnbr(n / 10);

    char res = n % 10 + '0';
    write(1, &res, 1);
    count++;

	return (count);
}

int ft_printhex(unsigned int n)
{
    char hex[] = "0123456789abcdef";
    int count = 0;
    if (n >= 16)
        count += ft_printhex(n / 16);
    write(1, &hex[n % 16], 1);
    count++;
    return (count);
}

int ft_printf(const char *text, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, text);
    while (text[i])
    {
        if (text[i] == '%' && text[i+1])
        {
            i++;
            if (text[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (text[i] == 'd')
                count += ft_putnbr(va_arg(args, int));
            else if (text[i] == 'x')
                count += ft_printhex(va_arg(args, unsigned int));
            else 
            {
                write(1, &text[i], 1);
                count++;
            }
        }
        else 
        {
            write(1, &text[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}

#include <stdio.h>
int	main(void)
{
	// int a = -2147483648;

    // //printf
    // printf("printf: \n");
	// int i = printf("%x", a);
	// printf("\n");
    // printf("%d\n", i);
	// printf("\n");

    // //ft_printf
    // printf("ft_printf: \n");
	// int j = ft_printhex(a);
	// printf("\n");
    // printf("%d\n", j);
	// printf("\n");

    ft_printf("Ft_printf: %s\n", "toto");
	printf("printf: %s\n", "toto");
	ft_printf("Ft_printf: Magic %s is %d\n", "number", 42);
	printf("printf: Magic %s is %d\n", "number", 42);
	ft_printf("Ft_printf: Hexadecimal for %d is %x\n", 42, 42);
	printf("printf: Hexadecimal for %d is %x\n", 42, 42);
}