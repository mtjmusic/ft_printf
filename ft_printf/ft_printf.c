/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:51:57 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/25 16:52:49 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type(char c, va_list args, int *count, void *temp)
{
	if (c == 'c')
		*count += (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (c == 's')
	{
		temp = va_arg(args, char *);
		if (!temp)
			*count += (ft_putstr_fd("(null)", 1), 6);
		else
			*count += ft_chars(temp);
	}
	else if (c == 'd' || c == 'i')
		*count += ft_ints(va_arg(args, int));
	else if (c == 'u')
		*count += ft_unints(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		*count += ft_hexa(va_arg(args, unsigned int), c);
	else if (c == 'p')
	{
		temp = va_arg(args, void *);
		if (!temp)
			*count += (ft_putstr_fd("(nil)", 1), 5);
		else
			*count += ft_pointers(temp);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	void	*temp;

	count = 0;
	if (!str)
		return (-1);
	temp = NULL;
	va_start(args, str);
	str = (char *)str;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				count += (ft_putchar_fd('%', 1), 1);
			ft_check_type(*str, args, &count, temp);
		}
		else
			count += (ft_putchar_fd(*str, 1), 1);
		str++;
	}
	va_end(args);
	return (count);
}

/*
void	test_print(const char *format, ...)
{
	va_list	args;
	void	*arg;

	va_start(args, format);
	arg = va_arg(args, void *);
	printf("P__ ");
	printf("           COUNT:  %d\n", printf(format, arg));
	printf("F__ ");
	fflush(stdout);
	printf("           COUNT:  %d\n", ft_printf(format, arg));
	va_end(args);
}

#include "stdint.h"
#include <stdbool.h>

int	main(void)
{
	// Test NULL values
	test_print("NULL AS POINTER:     %p ", NULL);
	test_print("NULL AS STRING :     %s", NULL);
	test_print("NULL AS INT    :     %d     ", NULL);
	test_print("NULL AS UINT   :     %u     ", NULL);
	// Test integers
	test_print("INT NEGATIVE   :     %i", -12345);
	test_print("INT            :     %i", 123456);
	test_print("INT            :     %i", 100000);
	test_print("INT            :     %i     ", 0);
	test_print("INTMAX         :     %i ", INT_MAX);
	test_print("INTMIN         :     %i", INT_MIN);
	test_print("UINT           :     %u ", (unsigned int)INT_MAX + 1236353);
	test_print("UINTMAX        :     %u ", UINT_MAX);
	// Test characters
	test_print("CHAR           :     %c", 'A');
	test_print("CHAR (NUMBER)  :     %c", 65);
	test_print("CHAR (NULL)    :     %c ", 0);
	// Test strings
	test_print("STRING         :     %s", "Hello, World!");
	test_print("EMPTY STRING   :     %s             ", "");
	// Test hexadecimal
	test_print("HEX (LOWER)    :     %x  ", 0xabcdef);
	test_print("HEX NUM        :     %x  ", 12345678);
	test_print("HEX (UPPER)    :     %X  ", 0xABCDEF);
	test_print("HEX (LONG)     :     %x", 0xFFFFFFFFFFFF);
	test_print("HEX (NEGATIVE) :     %x", -0xabcdef);
	//return(0);
	test_print("LONG HEX       :     %X   ", 0xABCDEL);
	test_print("HEX (ZERO)     :     %x       ", 0);
	// Test pointers
	int num = 42;
	test_print("POINTER        :     %p", &num);
	// Test percent sign
	test_print("PERCENT        :     %%");
	// printf("P__ PERCENT AT END       :     %");
	// printf("\n");
	// fflush(stdout);
	// ft_printf("F__ PERCENT AT END       :     %");
	// fflush(stdout);
	// printf("\n");
	// fflush(stdout);
	//printf("P__ SINGLE PERCENT AT END       :     %\n");
	// printf("\n");
	// fflush(stdout);
	// ft_printf("F__ SINGLE PERCENT AT END       :     %\n");
	// Test multiple conversions
	// Test edge cases
	test_print("LONG STRING    :     %s",
		"This is a very long string that goes on and on...");
	printf("           COUNT:  %d\n", printf("P__ MIXED          :     %d %s %x
			%c", 42, "test", 255, 'Z'));
	printf("           COUNT:  %d\n", ft_printf("F__ MIXED          :     %d %s
			%x %c", 42, "test", 255, 'Z'));
	printf("           COUNT:  %d\n", printf("P__ MANY ARGS      :     %d %d %d
			%d %d", 1, 2, 3, 4, 5));
	printf("           COUNT:  %d\n", ft_printf("F__ MANY ARGS      :     %d %d
			%d %d %d", 1, 2, 3, 4, 5));
	return (0);
}*/

/*  #include <stdio.h>
int	main(void)
{
	int ft_len, printf_len;

	// Test 1: Basic functionality
	ft_len = ft_printf("Heeello, world!\n");
	printf_len = printf("Heeello, world!\n");
	printf("Test 1 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 2: Multiple conversions
	ft_len = ft_printf("Char: %c, String: %s, Pointer: %p\n"
		, 'A', "test", (void *)0x12345678);
	printf_len = printf("Char: %c, String: %s, Pointer: %p\n"
		, 'A', "test", (void *)0x12345678);
	printf("Test 2 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 3: Integers
	ft_len = ft_printf("Decimal: %d, Integer: %i, Unsigned: %u\n"
		, -42, 42, UINT_MAX);
	printf_len = printf("Decimal: %d, Integer: %i, Unsigned: %u\n"
		, -42, 42, UINT_MAX);
	printf("Test 3 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 4: Hexadecimal
	ft_len = ft_printf("Hex (lower): %x, Hex (upper): %X\n", 255, 255);
	printf_len = printf("Hex (lower): %x, Hex (upper): %X\n", 255, 255);
	printf("Test 4 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 5: Percent sign
	ft_len = ft_printf("Percent sign: %%\n");
	printf_len = printf("Percent sign: %%\n");
	printf("Test 5 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 6: Edge cases - NULL pointer and empty string
	ft_len = ft_printf("NULL string: %s, Empty string: %s\n", NULL, "");
	//printf_len = printf("NULL string: %s, Empty string: %s\n", NULL, "");
	printf("Test 6 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 7: Edge cases - INT_MIN and INT_MAX
	ft_len = ft_printf("INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
	printf_len = printf("INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
	printf("Test 7 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 8: Edge cases - Long hex values
	ft_len = ft_printf("Long hex: %x\n", UINT_MAX);
	printf_len = printf("Long hex: %x\n", UINT_MAX);
	printf("Test 8 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 9: Mixed types
	ft_len = ft_printf("Mixed: %d %s %x %c%%\n", 42, "test", 255, 'Z');
	printf_len = printf("Mixed: %d %s %x %c%%\n", 42, "test", 255, 'Z');
	printf("Test 9 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 10: No specifiers
	ft_len = ft_printf("No specifiers in this string.\n");
	printf_len = printf("No specifiers in this string.\n");
	printf("Test 10 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	// Test 11 Empty pointer
	ft_len = ft_printf("Empty pointer %p\n", NULL);
	printf_len = printf("Empty pointer %p\n", NULL);
	printf("Test 11 - ft_printf: %d, printf: %d\n\n", ft_len, printf_len);

	return (0);
}  */