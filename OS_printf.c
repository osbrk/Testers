/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:00:18 by osukhore          #+#    #+#             */
/*   Updated: 2025/12/05 14:35:31 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

static	void style(char style)
{
	//BLUE
	if (style == 'B')
		printf("\e[34m\n");
	else if (style == 'b')
		printf("\e[34m");
	//GREEN
	else if(style == 'G')
		printf("\e[32m");
	//ERROR
	else if(style == 'E')
		printf("\e[1;31;7m");
	//TITLE
	else if(style == 'T')
		printf("\e[1;7m");
	//RESET TO BLACK
	else if(style == 'R')
		printf("\e[0m\n");
	else if(style == 'r')
		printf("\e[0m");
}

int	main(int argc, char **argv)
{
	//HERE WE GO!
	char	*argv_str;
	char	argv_c;
	int		argv_n;

	//ERROR CHECK
	if (argc < 2)
	{
		printf("\n--------------------------------------------\n");
		style('E');
		printf("INPUT ");
		style('R');
		style('T');
		printf("Need ARGV to work with: \n\n"
			" 1. String \n"
			" 2. Char \n"
			" 3. Number ");
		style('R');
		printf("--------------------------------------------\n");
		return (0);
	}
	//FILE NAME
	style('T');
	printf("\n ft_printft.c \n");
	style('R');

	argv_str = argv[1];
	argv_c = argv[2][0];
	argv_n = ft_atoi(argv[3]);

	printf("LEGEND: ");
	style('G');
	printf("  Original printf");
	style('r');
	printf(" | ");
	style('b');
	printf(" My ft_printf");
	style('R');

	//TEST 01: ARGV
	int real;
	int mine;

	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 01: ARGV \n\n");
	style('r');

	//s
	printf("%%s String:\n");
	style('G');
	real = printf("%s", argv_str);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%s", argv_str);
	style('R');
	printf(" Return: %d\n\n\n", mine);


	//c
	printf("%%c Character\n");
	style('G');
	real = printf("%c", argv_c);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%c", argv_c);
	style('R');
	printf(" Return: %d\n\n\n", mine);

	//%
	printf("%%%% Percentage\n");
	style('G');
	real = printf("%%");
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%%");
	style('R');
	printf(" Return: %d\n\n\n", mine);


	//d | i
	printf("%%d Decimal\n");
	style('G');
	real = printf("%d", argv_n);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%d", argv_n);
	style('R');
	printf(" Return: %d\n\n\n", mine);

	//i
	printf("%%i Integer\n");
	style('G');
	real = printf("%i", argv_n);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%i", argv_n);
	style('R');
	printf(" Return: %d\n\n\n", mine);


	//u
	printf("%%u Unsigned Decimal\n");
	style('G');
	real = printf("%u", (unsigned int)argv_n);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%u", (unsigned int)argv_n);
	style('R');
	printf(" Return: %d\n\n\n", mine);


	//x
	printf("%%x Hex lowercase\n");
	style('G');
	real = printf("%x", (unsigned int)argv_n);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%x", (unsigned int)argv_n);
	style('R');
	printf(" Return: %d\n\n\n", mine);


	//X
	printf("%%X Hex uppercase\n");
	style('G');
	real = printf("%X", (unsigned int)argv_n);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%X", (unsigned int)argv_n);
	style('R');
	printf(" Return: %d\n\n\n", mine);


	//p
	printf("%%p Pointer\n");
	style('G');
	real = printf("%p", (void *)argv_str);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%p", (void *)argv_str);
	style('R');
	printf(" Return: %d\n\n", mine);

	printf("\n--------------------------------------------\n\n");

	//TEST 02: STRINGS
	style('T');
	printf(" TEST 02: STRINGS %%s \n\n");
	style('r');

	printf("Input: Never gonna give you up, never gonna let you down\n");
	style('G');
	real = printf("%s", "Never gonna give you up, never gonna let you down");
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%s", "Never gonna give you up, never gonna let you down");
	style('R');
	printf(" Return: %d\n\n\n", mine);

	// empty string
	printf("Input: \"\":\n");
	style('G');
	real = printf("%s", "");
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%s", "");
	style('R');
	printf(" Return: %d\n\n\n", mine);

	// NULL string
	printf("Input : NULL\n");
	char *null_str = NULL;
	style('G');
	real = printf("%s", null_str);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%s", null_str);
	style('R');
	printf(" Return: %d\n", mine);

	//TEST 03: CHARACTERS
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 03: CHARACTERS %%c \n\n");
	style('r');

	// normal char
	printf("Char 'A':\n");
	style('G');
	real = printf("%c", 'A');
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%c", 'A');
	style('R');
	printf(" Return: %d\n\n\n", mine);

	// null char
	printf("Null char '\\0':\n");
	style('G');
	real = printf("%c", '\0');
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%c", '\0');
	style('R');
	printf(" Return: %d\n", mine);

	//TEST 04: SIGNED INTS
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 04: SIGNED %%d | %%i \n\n");
	style('r');

	// 0 | +ive | -ive
	printf("Input %%d: 0 | 42 | -42\n");
	style('G');
	real = printf("%d | %d | %d", 0, 42, -42);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", real);

	style('B');
	mine = ft_printf("%d | %d | %d", 0, 42, -42);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n\n\n", mine);

	// INT_MAX | INT_MIN
	printf("Input %%d: INT_MAX | INT_MIN\n");
	style('G');
	real = printf("%d | %d", INT_MAX, INT_MIN);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", real);

	style('B');
	mine = ft_printf("%d | %d", INT_MAX, INT_MIN);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n\n\n", mine);

	// 0 | +ive | -ive
	printf("Input %%i: 0 | 42 | -42\n");
	style('G');
	real = printf("%i | %i | %i", 0, 42, -42);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", real);

	style('B');
	mine = ft_printf("%i | %i | %i", 0, 42, -42);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n\n\n", mine);

	// INT_MAX | INT_MIN
	printf("Input %%i: INT_MAX | INT_MIN\n");
	style('G');
	real = printf("%i | %i", INT_MAX, INT_MIN);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", real);

	style('B');
	mine = ft_printf("%d | %d", INT_MAX, INT_MIN);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n\n", mine);

	//TEST 05: UNSIGNED
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 05: UNSIGNED %%u \n\n");
	style('r');

	// 0 | +ive
	printf("Input: 0 | 42\n");
	style('G');
	real = printf("%u | %u", 0, 42);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", real);

	style('B');
	mine = ft_printf("%u | %u", 0, 42);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n\n\n", mine);

	// UINT_MAX
	printf("UINT_MAX:\n");
	style('G');
	real = printf("%u", UINT_MAX);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", real);

	style('B');
	mine = ft_printf("%u", UINT_MAX);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", mine);

	//TEST 06: HEXADECIMAL
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 06: HEX %%x | %%X \n\n");
	style('r');

	// 0
	printf("Input: 0\n");
	style('G');
	real = printf("%x | %X", 0, 0);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n", real);

	style('B');
	mine = ft_printf("%x | %X", 0, 0);
	style('R');
	printf(" Return: %d (incl. pipes & spaces)\n\n\n", mine);

	// UINT_MAX
	printf("UINT_MAX:\n");
	style('G');
	real = printf("%x | %X", UINT_MAX, UINT_MAX);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%x | %X", UINT_MAX, UINT_MAX);
	style('R');
	printf(" Return: %d\n", mine);

	//TEST 07: POINTERS
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 07: POINTERS %%p \n\n");
	style('r');

	int		pointer;
	void	*ptr_pointer = &pointer;
	void	*ptr_null = NULL;

	// NULL
	printf("NULL pointer:\n");
	style('G');
	real = printf("%p", ptr_null);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%p", ptr_null);
	style('R');
	printf(" Return: %d\n\n\n", mine);

	// pointer
	printf("Example pointer :\n");
	style('G');
	real = printf("%p", ptr_pointer);
	style('R');
	printf(" Return: %d\n", real);

	style('B');
	mine = ft_printf("%p", ptr_pointer);
	style('R');
	printf(" Return: %d\n", mine);

	//TEST 08: MIXED
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 08: MORE \n\n");
	style('r');

	printf("Mixed string:\n");
	style('G');
	real = printf("%c %s %p %d %i %u %x %X %%", 'N', "ever gonna give you up",
		(void *)"test", -42, 255, 42042, 12345, 5678);
	style('R');
	printf(" Return: %d\n", real);


	style('B');
	mine = ft_printf("%c %s %p %d %i %u %x %X %%", 'N', "ever gonna give you up",
		(void *)"test", -42, 255, 42042, 12345, 5678);
	style('R');
	printf(" Return: %d\n\n\n", mine);

		printf("Double mixed string:\n");
	style('G');
	real = printf("%c %c %s %s %p %p %d %d %i %i %u %u %x %x %X %X %% %%",
		'N', 'e', "ver gonna give you up", " Never gonna let you down",
		(void *)"test", (void *)"testing", -42, 42, 255, -255, 42042, 12345,
		12345, 5678, 1212, 3232);
	style('R');
	printf(" Return: %d\n", real);


	style('B');
	mine = ft_printf("%c %c %s %s %p %p %d %d %i %i %u %u %x %x %X %X %% %%",
		'N', 'e', "ver gonna give you up", " Never gonna let you down",
		(void *)"test", (void *)"testing", -42, 42, 255, -255, 42042, 12345,
		12345, 5678, 1212, 3232);
	style('R');
	printf(" Return: %d\n\n\n", mine);


		printf("cspdiuxX:\n");
	style('G');
	real = printf("cspdiuxX");
	style('R');
	printf(" Return: %d\n", real);


	style('B');
	mine = ft_printf("cspdiuxX");
	style('R');
	printf(" Return: %d\n", mine);

	printf("\n--------------------------------------------\n\n");
	style('T');
	printf(" Job done! \n");
	style('R');
	printf("\n");

}

