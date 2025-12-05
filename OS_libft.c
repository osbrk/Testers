/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:49:06 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/05 12:46:52 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>

static void	ft_free(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}
static void	helper_striteri(unsigned int i, char *str)
{
	i = 0;
	if (str[i] >= 97 && str[i] <= 122)
		str[i] -= 32;
}
static char	helper_strmapi(unsigned int i, char c)
{
	i = 32;
	if (c >= 97 && c <= 122)
		c -= i;
	return (c);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("\e[1;31;7m ERROR! \e[0m"
			"\e[1;7m Need ARGV to work with! \e[0m\n"
			"\e[1;7m |1. Function name| \e[0m\n");
		return (0);
	}
	char	*argv_function = argv[1];

	if ((strcmp(argv_function, "atoi") == 0) ||
		(strcmp(argv_function, "Atoi") == 0))
	{
		char	*str;
		char	*argv_s;
		int		real;
		int		mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \e[0m\n");
			return (0);
		}
		argv_s = argv[2];

		//FILE NAME
		printf("\n\e[1;7m ft_atoi.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("Input ARGV\t|%s|\n\n", argv_s);
		real = atoi(argv_s);
		mine = ft_atoi(argv_s);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n\n", mine);
		printf("--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple tests\n\n");

		//POSITIVE
		str = "       42a042b483647";
		real = atoi(str);
		mine = ft_atoi(str);
		printf("Input +ive\t|%s|\n", str);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n\n", mine);

		//NEGATIVE
		str = "       -42!042b483647";
		real = atoi(str);
		mine = ft_atoi(str);
		printf("Input -ive\t|%s|\n", str);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n\n", mine);

		//ZERO
		str = "      0zero";
		real = atoi(str);
		mine = ft_atoi(str);
		printf("Input Zero\t|%s|\n", str);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n\n", mine);

		//INT MAX
		str = "   \t   2147483647intmax";
		real = atoi(str);
		mine = ft_atoi(str);
		printf("Input Int Max\t|%s|\n", str);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n\n", mine);

		//INT MIN
		str = "      -2147483648intmin";
		real = atoi(str);
		mine = ft_atoi(str);
		printf("Input Int Min\t|%s|\n", str);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);

		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "bzero") == 0) ||
		(strcmp(argv_function, "Bzero") == 0))
	{
		char	str1_real[] = "Nevergonnagiveyouup";
		char	str1_mine[] = "Nevergonnagiveyouup";
		char	str2_real[] = "Nevergonnagiveyouup";
		char	str2_mine[] = "Nevergonnagiveyouup";
		char	*argv_s;
		char	*argv_real;
		char	*argv_mine;
		size_t	i;
		size_t	n = 6;
		size_t	index = 5;
		size_t	argv_n;
		size_t	argv_len;
		size_t	str_len;

		//ERROR CHECK
		if (argc < 4)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \n |3. Int| \e[0m\n");
			return (0);
		}
		argv_s = argv[2];
		argv_real = ft_strdup(argv_s);
		argv_mine = ft_strdup(argv_s);
		if (argv_real == 0 || argv_mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_real)
				free(argv_real);
			if (argv_mine)
				free(argv_mine);
			return (0);
		}
		argv_n = (size_t)ft_atoi(argv[3]);
		argv_len = ft_strlen(argv_s);

		//FILE NAME
		printf("\n\e[1;7m ft_bzero.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		str_len = ft_strlen(str1_real);
		printf("Test 1: Using ARGV\n");
		printf("%s\n|n = %zu|\n\n", argv_s, argv_n);
		bzero(argv_real, argv_n);
		printf("Original:\n");
		i = 0;
		while (i < argv_len)
		{
			if (argv_real[i] == 0)
				printf("\e[92m0\e[0m");
			else
				printf("%c", argv_real[i]);
			i++;
		}
		printf("\n\n");

		ft_bzero(argv_mine, argv_n);
		printf("My result:\n");
		i = 0;
		while (i < argv_len)
		{
			if (argv_mine[i] == 0)
				printf("\e[34m0\e[0m");
			else
				printf("%c", argv_mine[i]);
			i++;
		}
		printf("\n\n--------------------------------------------\n\n");
		free(argv_real);
		free(argv_mine);

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n|n = %zu|\n\n", str1_real, n);
		bzero(str1_real, n);
		printf("Original:\n");
		i = 0;
		while (i < str_len)
		{
			if (str1_real[i] == 0)
				printf("\e[92m0\e[0m");
			else
				printf("%c", str1_real[i]);
			i++;
		}
		printf("\n\n");

		ft_bzero(str1_mine, n);
		printf("My result:\n");
		i = 0;
		while (i < str_len)
		{
			if (str1_mine[i] == 0)
				printf("\e[34m0\e[0m");
			else
				printf("%c", str1_mine[i]);
			i++;
		}
		printf("\n\n--------------------------------------------\n\n");

		//TEST 3: SIMPLE TEST WITH OFFSET
		char	*real_offset = str2_real + index;
		char	*mine_offset = str2_mine + index;
		printf("Test 3: Simple with offset\n");
		printf("%s\n|n = %zu| |offset = %zu|\n\n", str2_real, n, index);
		bzero(real_offset, n);
		printf("Original:\n");
		i = 0;
		while (i < str_len)
		{
			if (str2_real[i] == 0)
				printf("\e[92m0\e[0m");
			else
				printf("%c", str2_real[i]);
			i++;
		}
		printf("\n\n");

		ft_bzero(mine_offset, n);
		printf("My result:\n");
		i = 0;
		while (i < str_len)
		{
			if (str2_mine[i] == 0)
				printf("\e[34m0\e[0m");
			else
				printf("%c", str2_mine[i]);
			i++;
		}
		printf("\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "calloc") == 0) ||
		(strcmp(argv_function, "Calloc") == 0))
	{
		size_t	nmemb = 2;
		size_t	size = 5;
		size_t	i;
		size_t	argv_nmemb;
		size_t	argv_size;
		char	*argv_real;
		char	*argv_mine;
		char	*real;
		char	*mine;

		//ERROR CHECK
		if (argc < 4)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. nmemb| \n |3. size| \e[0m\n");
			return (0);
		}
		argv_nmemb = (size_t)ft_atoi(argv[2]);
		argv_size = (size_t)ft_atoi(argv[3]);
		argv_real = calloc(argv_nmemb, argv_size);
		argv_mine = ft_calloc(argv_nmemb, argv_size);
		real = calloc(nmemb, size);
		mine = ft_calloc(nmemb, size);
		if (argv_real == 0 || argv_mine == 0 || real == 0 || mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_real)
				free(argv_real);
			if (argv_mine)
				free(argv_mine);
						if (real)
				free(real);
			if (mine)
				free(mine);
			return (0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_calloc.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("|nmemb = %zu| |size = %zu|\n\n", argv_nmemb, argv_size);
		printf("Original:\n");
		i = 0;
		while (i < argv_nmemb * argv_size)
		{
			if (argv_real[i] == 0)
				printf("\e[92m0\e[0m");
			else
				printf("%c", argv_real[i]);
			i++;
		}
		printf("\n\n");

		printf("My result:\n");
		i = 0;
		while (i < argv_nmemb * argv_size)
		{
			if (argv_mine[i] == 0)
				printf("\e[34m0\e[0m");
			else
				printf("%c", argv_mine[i]);
			i++;
		}
		printf("\n\n--------------------------------------------\n\n");
		free(argv_real);
		free(argv_mine);

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("|nmemb = %zu| |size = %zu|\n\n", nmemb, size);
		printf("Original:\n");
		i = 0;
		while (i < nmemb * size)
		{
			if (real[i] == 0)
				printf("\e[92m0\e[0m");
			else
				printf("%c", real[i]);
			i++;
		}
		printf("\n\n");

		printf("My result:\n");
		i = 0;
		while (i < nmemb * size)
		{
			if (mine[i] == 0)
				printf("\e[34m0\e[0m");
			else
				printf("%c", mine[i]);
			i++;
		}
		printf("\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		free(real);
		free(mine);
		return (0);
	}
	else if ((strcmp(argv_function, "isalnum") == 0) ||
		(strcmp(argv_function, "Isalnum") == 0))
	{
		int		c = 'A';
		int		real;
		int		mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character| \e[0m\n");
			return (0);
		}
		int		argv_c  = argv[2][0];

		//FILE NAME
		printf("\n\e[1;7m ft_isalnum.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("|%c|\n\n", argv_c);
		real = isalnum(argv_c);
		mine = ft_isalnum(argv_c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple test\n");
		printf("|%c|\n\n", c);
		real = isalnum(c);
		mine = ft_isalnum(c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "isalpha") == 0) ||
		(strcmp(argv_function, "Isalpha") == 0))
	{
		int		c = 'A';
		int		real;
		int		mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character| \e[0m\n");
			return (0);
		}
		int		argv_c = argv[2][0];

		//FILE NAME
		printf("\n\e[1;7m ft_isalpha.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("|%c|\n\n", argv_c);
		real = isalpha(argv_c);
		mine = ft_isalpha(argv_c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple test\n");
		printf("|%c|\n\n", c);
		real = isalpha(c);
		mine = ft_isalpha(c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "isascii") == 0) ||
		(strcmp(argv_function, "Isascii") == 0))
	{
		int		c = 'A';
		int		real;
		int		mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character| \e[0m\n");
			return (0);
		}
		int		argv_c = argv[2][0];

		//FILE NAME
		printf("\n\e[1;7m ft_isascii.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("|%c|\n\n", argv_c);
		real = isascii(argv_c);
		mine = ft_isascii(argv_c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple test\n");
		printf("|%c|\n\n", c);
		real = isascii(c);
		mine = ft_isascii(c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "isdigit") == 0) ||
		(strcmp(argv_function, "Isdigit") == 0))
	{
		int		c = 'A';
		int		real;
		int		mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character/Int| \e[0m\n");
			return (0);
		}
		int		argv_c = argv[2][0];

		//FILE NAME
		printf("\n\e[1;7m ft_isdigit.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("|%c|\n\n", argv_c);
		real = isdigit(argv_c);
		mine = ft_isdigit(argv_c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple test\n");
		printf("|%c|\n\n", c);
		real = isdigit(c);
		mine = ft_isdigit(c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "isprint") == 0) ||
		(strcmp(argv_function, "Isprint") == 0))
	{
		int		c = 'A';
		int		real;
		int		mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character/Int| \e[0m\n");
			return (0);
		}
		int		argv_c = argv[2][0];

		//FILE NAME
		printf("\n\e[1;7m ft_isprint.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("|%c|\n\n", argv_c);
		real = isprint(argv_c);
		mine = ft_isprint(argv_c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple test\n");
		printf("|%c|\n\n", c);
		real = isprint(c);
		mine = ft_isprint(c);
		printf("Original:\t\e[92m%d\e[0m\n", real);
		printf("My result:\t\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "itoa") == 0) ||
		(strcmp(argv_function, "Itoa") == 0))
	{
		char	*argv_str;
		int		argv_n;
		int		n;
		char	*mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Int| \e[0m\n");
			return (0);
		}
		argv_str = argv[2];
		argv_n = ft_atoi(argv_str);
		if (argv_n == 0 && argv_str[0] != '0')
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Give me a proper number! \e[0m\n");
			return (0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_itoa.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: ARGV
		printf("Test 1: Using ARGV\n\n");
		printf("Input ARGV\t%s\n", argv_str);
		mine = ft_itoa(argv_n);
		if (mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result:\t\e[34m%s\e[0m\n", mine);
		free(mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: SIMPLE VALUE
		printf("Test 2: Simple test\n\n");

		//POSITIVE
		n = 42;
		printf("Input +ive\t%d\n", n);
		mine = ft_itoa(n);
		if (mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result :\t\e[34m%s\e[0m\n\n", mine);
		free(mine);

		//NEGATIVE
		n = -42;
		printf("Input -ive\t%d\n", n);
		mine = ft_itoa(n);
		if (mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result:\t\e[34m%s\e[0m\n\n", mine);
		free(mine);

		//ZERO
		n = 0;
		printf("Input Zero\t%d\n", n);
		mine = ft_itoa(n);
		if (mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result:\t\e[34m%s\e[0m\n\n", mine);
		free(mine);

		//INT MAX
		n = INT_MAX;
		printf("Input Int Max\t%d\n", n);
		mine = ft_itoa(n);
		if (mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result: \t\e[34m%s\e[0m\n\n", mine);
		free(mine);

		//INT MIN
		n = INT_MIN;
		printf("Input Int Min\t%d\n", n);
		mine = ft_itoa(n);
		if (mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result: \t\e[34m%s\e[0m\n", mine);
		free(mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "memchr") == 0) ||
		(strcmp(argv_function, "Memchr") == 0))
	{
		char			str[] = "Never gonna give you up";
		char			*real;
		char			*mine;
		char			*argv_str;
		int				argv_c;
		size_t			argv_n;
		int				c = 'g';
		size_t			n = 10;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\e[0m\n"
				"\e[1;7m |2. String| \n |3. Character| \n |4. Int| \e[0m\n");
			return (0);
		}
		argv_str = argv[2];
		argv_c = argv[3][0];
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_memchr.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n|c = %c| |n = %zu|\n\n", argv_str, argv_c, argv_n);
		printf("Original:\n");
		real = memchr(argv_str, argv_c, argv_n);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\n");
		mine = ft_memchr(argv_str, argv_c, argv_n);
		if (mine)
			printf("\e[34m%s\e[0m\n\n", mine);
		else
			printf("\e[34m(null)\e[0m\n\n");

		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE
		printf("Test 2: Simple test\n");
		printf("%s\n|c = %c| |n = %zu|\n\n", str, c, n);
		printf("Original:\n");
		real = memchr(str, c, n);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\n");
		mine = ft_memchr(str, c, n);
		if (mine)
			printf("\e[34m%s\e[0m\n", mine);
		else
			printf("\e[34m(null)\e[0m\n");
		printf("--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "memcmp") == 0) ||
		(strcmp(argv_function, "Memcmp") == 0))
	{
		char	str1[] = "Never gonna give you up,";
		char	str2[] = "Never gonna let you down";
		size_t	n = 20;
		char	*argv_str1;
		char	*argv_str2;
		size_t	argv_n;
		int		real;
		int		mine;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function|\e[0m\n"
				"\e[1;7m |2. String 1| \n |3. String 2| \n |4. Int| \e[0m\n");
			return (0);
		}
		argv_str1 = argv[2];
		argv_str2 = argv[3];
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_memcmp.c  \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("s1 =\t%s\ns2 =\t%s\n|n = %zu|\n\n", argv_str1, argv_str2, argv_n);
		printf("Original:\n");
		real = memcmp(argv_str1, argv_str2, argv_n);
		printf("\e[92m%d\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memcmp(argv_str1, argv_str2, argv_n);
		printf("\e[34m%d\e[0m\n\n", mine);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("s1 =\t%s\ns2 =\t%s\n|n = %zu|\n\n", str1, str2, n);
		printf("Original:\n");
		real = memcmp(str1, str2, n);
		printf("\e[92m%d\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memcmp(str1, str2, n);
		printf("\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "memcpy") == 0) ||
		(strcmp(argv_function, "Memcpy") == 0))
	{
		char	src[] = "Never gonna let you down";
		char	dest1[] = "make you cry, never gonna run around";
		char	dest2[] = "make you cry, never gonna run around";
		size_t	n = 10;
		char	*argv_dest1;
		char	*argv_dest2;
		char	*argv_src;
		size_t	argv_n;
		char	*real;
		char	*mine;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function|\e[0m\n"
				"\e[1;7m |2. String dest| \n |3. String src| \n |4. Int| \e[0m\n");
			return (0);
		}
		argv_dest1 = ft_strdup(argv[2]);
		argv_dest2 = ft_strdup(argv[2]);
		argv_src = ft_strdup(argv[3]);
		if (argv_dest1 == 0 || argv_dest2 == 0 || argv_src == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_dest1)
				free(argv_dest1);
			if (argv_dest2)
				free(argv_dest2);
			if (argv_src)
				free(argv_src);
			return (0);
		}
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_memcpy.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("dest =\t%s\nsrc =\t%s\n|n = %zu|\n\n",
			argv_dest1, argv_src, argv_n);
		printf("Original:\n");
		real = memcpy(argv_dest1, argv_src, argv_n);
		printf("\e[92m%s\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memcpy(argv_dest2, argv_src, argv_n);
		printf("\e[34m%s\e[0m\n\n", mine);

		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("dest =\t%s\nsrc =\t%s\n|n = %zu|\n\n", dest1, src, n);
		printf("Original:\n");
		real = memcpy(dest1, src, n);
		printf("\e[92m%s\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memcpy(dest2, src, n);
		printf("\e[34m%s\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		free(argv_dest1);
		free(argv_dest2);
		free(argv_src);
		return (0);
	}
	else if ((strcmp(argv_function, "memmove") == 0) ||
		(strcmp(argv_function, "Memmove") == 0))
	{
		char	src[] = "Never gonna let you down";
		char	dest1[] = "make you cry, never gonna run around";
		char	dest2[] = "make you cry, never gonna run around";
		size_t	n = 10;
		char	*argv_dest1;
		char	*argv_dest2;
		char	*argv_src;
		size_t	argv_n;
		char	*real;
		char	*mine;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\e[0m\n"
				"\e[1;7m |2. String dest| \n |3. String src| \n |4. Int| \e[0m\n");
			return (0);
		}
		argv_dest1 = ft_strdup(argv[2]);
		argv_dest2 = ft_strdup(argv[2]);
		argv_src = ft_strdup(argv[3]);
		if (argv_dest1 == 0 || argv_dest2 == 0 || argv_src == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_dest1)
				free(argv_dest1);
			if (argv_dest2)
				free(argv_dest2);
			if (argv_src)
				free(argv_src);
			return (0);
		}
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_memmove.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("dest =\t%s\nsrc =\t%s\n|n = %zu|\n\n",
			argv_dest1, argv_src, argv_n);
		printf("Original:\n");
		real = memmove(argv_dest1, argv_src, argv_n);
		printf("\e[92m%s\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memmove(argv_dest2, argv_src, argv_n);
		printf("\e[34m%s\e[0m\n\n", mine);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("dest =\t%s\nsrc =\t%s\n|n = %zu|\n\n", dest1, src, n);
		printf("Original:\n");
		real = memmove(dest1, src, n);
		printf("\e[92m%s\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memmove(dest2, src, n);
		printf("\e[34m%s\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		free(argv_dest1);
		free(argv_dest2);
		free(argv_src);
		return (0);
	}
	else if ((strcmp(argv_function, "memset") == 0) ||
		(strcmp(argv_function, "Memset") == 0))
	{
		char	str1[] = "Never gonna let you down";
		char	str2[] = "Never gonna let you down";
		int		c = 'A';
		size_t	n = 10;
		char	*argv_dst1;
		char	*argv_dst2;
		int		argv_c;
		size_t	argv_n;
		char	*real;
		char	*mine;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\e[0m\n"
				"\e[1;7m |2. String| \n |3. Character| \n |4. Int| \e[0m\n");
			return (0);
		}
		argv_dst1 = ft_strdup(argv[2]);
		argv_dst2 = ft_strdup(argv[2]);
		if (argv_dst1 == 0 || argv_dst2 == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_dst1)
				free(argv_dst1);
			if (argv_dst2)
				free(argv_dst2);
			return (0);
		}
		argv_c = argv[3][0];
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_memset.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n|c = %c| |n = %zu|\n\n", argv_dst1, argv_c, argv_n);
		printf("Original:\n");
		real = memset(argv_dst1, argv_c, argv_n);
		printf("\e[92m%s\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memset(argv_dst2, argv_c, argv_n);
		printf("\e[34m%s\e[0m\n\n", mine);

		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n|c = %c| |n = %zu|\n\n", str1, c, n);
		printf("Original:\n");
		real = memset(str1, c, n);
		printf("\e[92m%s\e[0m\n\n", real);

		printf("My result:\n");
		mine = ft_memset(str2, c, n);
		printf("\e[34m%s\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		free(argv_dst1);
		free(argv_dst2);
		return (0);
	}
	else if ((strcmp(argv_function, "putchar") == 0) ||
		(strcmp(argv_function, "Putchar") == 0))
	{
		int		fd;
		char	c = 'A';
		char	filename[] = "RESULT_putchar.txt";
		char	argv_c;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character/String| \e[0m\n");
			return(0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_putchar_fd.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//RUN FUNCTIONS
		argv_c = argv[2][0];
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0740);
		if (fd < 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7mfd bugged! (%d) \e[0m\n", fd);
			return(1);
		}

		//TEST 1: USING ARGV
		printf("Test 1: Create file using ARGV\n");
		printf("File name:\t|%s|\n", filename);
		printf("Contents:\t|%c|\n\n", argv_c);
		printf("My result:\e[34m\n");
		ft_putchar_fd(argv_c, fd);
		printf("\e[0m");
		printf("\e[34m|%s|\e[0m\n\n", filename);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("|%c| |fd = 1|\n\n", c);
		printf("My result:\e[34m\n");
		ft_putchar_fd(c, 1);
		printf("\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		close(fd);
		return(0);
	}
	else if ((strcmp(argv_function, "putendl") == 0) ||
		(strcmp(argv_function, "Putendl") == 0))
	{
		int		fd;
		char	str[] = "Never gonna give you up, never gonna let you down";
		char	filename[] = "RESULT_putendl.txt";
		char	*argv_str;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \e[0m\n");
			return (0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_putendl_fd.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//RUN FUNCTIONS
		argv_str = argv[2];
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0740);
		if (fd < 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m fd bugged! (%d) \e[0m\n", fd);
			return (1);
		}

		//TEST 1: USING ARGV
		printf("Test 1: Create file using ARGV\n");
		printf("File name:\t|%s|\n", filename);
		printf("Contents:\t|%s|\n\n", argv_str);
		printf("My result:\e[34m\n");
		ft_putendl_fd(argv_str, fd);
		printf("\e[0m");
		printf("\e[34m|%s|\e[0m\n\n", filename);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n|fd = 1|\n\n", str);
		printf("My result:\e[34m\n");
		ft_putendl_fd(str, 1);
		printf("\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		close(fd);
		return (0);
	}
	else if ((strcmp(argv_function, "putnbr") == 0) ||
		(strcmp(argv_function, "Putnbr") == 0))
	{
		int		fd;
		int		argv_n;
		int		n;
		char	filename[] = "RESULT_putnbr.txt";

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Int| \e[0m\n");
			return (0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_putnbr_fd.c \e[0m\n\n");

		//SHOW ORIGINAL INPUT
		argv_n = ft_atoi(argv[2]);
		printf("--------------------------------------------\n\n");

		//RUN FUNCTIONS
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0740);
		if (fd < 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m fd bugged! (%d) \e[0m\n", fd);
			return (1);
		}

		//TEST 1: USING ARGV
		printf("Test 1: Create file using ARGV\n");
		printf("File name:\t|%s|\n", filename);
		printf("Contents:\t|%d|\n\n", argv_n);
		printf("My result:\t");
		ft_putnbr_fd(argv_n, fd);
		printf("\e[34mCreated file: |%s|\e[0m\n\n", filename);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple tests\n");
		printf("|fd = 1|\n\n");

		//POSITIVE
		n = 42;
		printf("My result:\t|%d|\e[34m\n", n);
		ft_putnbr_fd(n, 1);
		printf("\e[0m\n");

		//NEGATIVE
		n = -42;
		printf("My result:\t|%d|\e[34m\n", n);
		ft_putnbr_fd(n, 1);
		printf("\e[0m\n");

		//ZERO
		n = 0;
		printf("My result:\t|%d|\e[34m\n", n);
		ft_putnbr_fd(n, 1);
		printf("\e[0m\n");

		//INT MAX
		n = INT_MAX;
		printf("My result:\t|%d|\e[34m\n", n);
		ft_putnbr_fd(n, 1);
		printf("\e[0m\n");

		//INT MIN
		n = INT_MIN;
		printf("My result:\t|%d|\e[34m\n", n);
		ft_putnbr_fd(n, 1);
		printf("\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		close(fd);
		return (0);
	}
	else if ((strcmp(argv_function, "putstr") == 0) ||
		(strcmp(argv_function, "Putstr") == 0))
	{
		int		fd;
		char	str[] = "Never gonna give you up, never gonna let you down";
		char	filename[] = "RESULT_putstr.txt";

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \e[0m\n");
			return (0);
		}
		char	*argv_str = argv[2];

		//FILE NAME
		printf("\n\e[1;7m ft_putstr_fd.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//RUN FUNCTIONS
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0740);
		if (fd < 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m fd bugged! (%d) \e[0m\n", fd);
			return (1);
		}

		//TEST 1: USING ARGV
		printf("Test 1: Create file using ARGV\n");
		printf("File name:\t|%s|\n", filename);
		printf("Contents:\t|%s|\n\n", argv_str);
		printf("My result:\t");
		ft_putstr_fd(argv_str, fd);
		printf("\e[34mCreated file: |%s|\e[0m\n\n", filename);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n|fd = 1|\n\n", str);
		printf("My result:\e[34m\n");
		ft_putendl_fd(str, 1);
		printf("\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		close(fd);
		return (0);
	}
	else if ((strcmp(argv_function, "split") == 0) ||
		(strcmp(argv_function, "Split") == 0))
	{
		char	*s = "Never gonna give you up, never gonna let you down";
		size_t	i;
		char	**str_array;
		char	c = ' ';

		//ERROR CHECK
		if (argc < 4)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\e[0m\n"
				"\e[1;7m |2. String| \n |3. Character| \e[0m\n");
			return (0);
		}
		char	argv_c  = argv[3][0];
		char	*argv_s = argv[2];

		//FILE NAME
		printf("\n\e[1;7m ft_split.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n|%c|\n\n", argv_s, argv_c);
		str_array = ft_split(argv_s, argv_c);
		printf("My result:\n");
		if (str_array == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		i = 0;
		while (str_array[i] != 0)
		{
			printf("\e[34m%zu: %s\e[0m\n", i, str_array[i]);
			i++;
		}
		printf("\e[34m%zu: %s\e[0m\n", i, str_array[i]);
		printf("\n");
		ft_free(str_array, i);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n|%c|\n\n", s, c);
		str_array = ft_split(s, c);
		printf("My result:\n");
		if (str_array == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		i = 0;
		while (str_array[i] != 0)
		{
			printf("\e[34m%zu: %s\e[0m\n", i, str_array[i]);
			i++;
		}
		printf("\e[34m%zu: %s\e[0m\n", i, str_array[i]);
		ft_free(str_array, i);
		printf("\n--------------------------------------------\n\n");
		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strchr") == 0) ||
		(strcmp(argv_function, "Strchr") == 0))
	{
		char	str[] = "Never gonna give you up";
		char	*mine;
		char	*real;
		int		c = 'g';

		//ERROR CHECK
		if (argc < 4)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Fucntion name|\e[0m\n"
				"\e[1;7m |2. String| \n |3. Character| \e[0m\n");
			return (0);
		}
		char	*argv_str  = argv[2];
		int		argv_c  = argv[3][0];

		//FILE NAME
		printf("\n\e[1;7m ft_strchr.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n|%c|\n\n", argv_str, argv_c);
		printf("Original:\n");
		real = strchr(argv_str, argv_c);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\n");
		mine = ft_strchr(argv_str, argv_c);
		if (mine)
			printf("\e[34m%s\e[0m\n\n", mine);
		else
			printf("\e[34m(null)\e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n|%c|\n\n", str, c);
		printf("Original:\n");
		real = strchr(str, c);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\n");
		mine = ft_strchr(str, c);
		if (mine)
			printf("\e[34m%s\e[0m\n", mine);
		else
			printf("\e[34m(null)\e[0m\n");

		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strdup") == 0) ||
		(strcmp(argv_function, "Strdup") == 0))
	{
		char	str[] = "Never gonna give you up";
		char	*argv_real;
		char	*argv_mine;
		char	*real;
		char	*mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \e[0m\n");
			return (0);
		}
		char	*argv_str  = argv[2];
		argv_real = strdup(argv_str);
		argv_mine = ft_strdup(argv_str);
		real = strdup(str);
		mine = ft_strdup(str);
		if (argv_real == 0 || argv_mine == 0 || real == 0 || mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_real)
				free(argv_real);
			if (argv_mine)
				free(argv_mine);
			if (real)
				free(real);
			if (mine)
				free(mine);
			return (0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_strdup.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n\n", argv_str);
		printf("Original:\n");
		printf("\e[92m%s\e[0m\n\n", argv_real);

		printf("My result:\n");
		printf("\e[34m%s\e[0m\n\n", argv_mine);
		printf("--------------------------------------------\n\n");
		free(argv_real);
		free(argv_mine);

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n\n", str);
		printf("Original:\n");
		printf("\e[92m%s\e[0m\n\n", real);

		printf("My result:\n");
		printf("\e[34m%s\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		free(real);
		free(mine);
		return (0);
	}
	else if ((strcmp(argv_function, "striteri") == 0) ||
		(strcmp(argv_function, "Striteri") == 0))
	{
		char	str[] = "Never gonna give you up, never gonna let you down";

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \e[0m\n");
			return (0);
		}
			char	*argv_str  = argv[2];

		//FILE NAME
		printf("\n\e[1;7m ft_striteri.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n\n", argv_str);
		printf("My result:\n");
		ft_striteri(argv_str, helper_striteri);
		printf("\e[34m%s\e[0m\n\n", argv_str);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n\n", str);
		printf("My result:\n");
		ft_striteri(str, helper_striteri);
		printf("\e[34m%s\e[0m\n", str);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strjoin") == 0) ||
		(strcmp(argv_function, "Strjoin") == 0))
	{
		char	const	s1[] = "Never gonna give you up, ";
		char	const	s2[] = "never gonna let you down";
		char			*join;
		char			*argv_join;

		//ERROR CHECK
		if (argc < 4)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\e[0m\n"
				"\e[1;7m |2. String 1| \n |3. String 2| \e[0m\n");
			return (0);
		}
		char	*argv_s1 = argv[2];
		char	*argv_s2  = argv[3];

		//FILE NAME
		printf("\n\e[1;7m ft_strjoin.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");
		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("s1 =\t%s\ns2 =\t%s\n\n", argv_s1, argv_s2);
		argv_join = ft_strjoin(argv_s1, argv_s2);
		if (argv_join == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result:\n\e[34m%s\e[0m\n\n", argv_join);
		printf("--------------------------------------------\n\n");
		free(argv_join);

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("s1 =\t%s\ns2 =\t%s\n\n", s1, s2);
		join = ft_strjoin(s1, s2);
		if (join == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			return (0);
		}
		printf("My result:\n\e[34m%s\e[0m\n", join);
		free(join);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strlcat") == 0) ||
		(strcmp(argv_function, "Strlcat") == 0))
	{
		char	dest1[100] = "Never gonna ";
		char	dest2[100] = "Never gonna ";
		char	src[] = "give you up, never gonna let you down";
		size_t	n = 35;
		size_t	real;
		size_t	mine;
		char	*argv_dest1;
		char	*argv_dest2;
		char	*argv_src;
		size_t	argv_n;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\n"
				" |2. String dest| \n |3. String src| \n"
				" |4. Int size| \e[0m\n");
			return (0);
		}

		argv_dest1 = ft_strdup(argv[2]);
		argv_dest2 = ft_strdup(argv[2]);
		argv_src = ft_strdup(argv[3]);
		if (argv_dest1 == 0 || argv_dest2 == 0 || argv_src == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_dest1)
				free(argv_dest1);
			if (argv_dest2)
				free(argv_dest2);
			if (argv_src)
				free(argv_src);
			return (0);
		}
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_strlcat.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("dest = %s\nsrc = %s\n|n = %zu|\n\n",
			argv_dest1, argv_src, argv_n);
		printf("Original:\t");
		real = strlcat(argv_dest1, argv_src, argv_n);
		printf("\e[92m%zu\e[0m\n", real);
		printf("\t\t\e[92m%s\e[0m\n\n", argv_dest1);

		printf("My result:\t");
		mine = ft_strlcat(argv_dest2, argv_src, argv_n);
		printf("\e[34m%zu\e[0m\n", mine);
		printf("\t\t\e[34m%s\e[0m\n\n", argv_dest2);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("dest = %s\nsrc = %s\n|n = %zu|\n\n", dest1, src, n);
		printf("Original:\t");
		real = strlcat(dest1, src, n);
		printf("\e[92m%zu\e[0m\n", real);
		printf("\t\t\e[92m%s\e[0m\n\n", dest1);

		printf("My result:\t");
		mine = ft_strlcat(dest2, src, n);
		printf("\e[34m%zu\e[0m\n", mine);
		printf("\t\t\e[34m%s\e[0m\n", dest2);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		free(argv_dest1);
		free(argv_dest2);
		free(argv_src);
		return (0);
	}
	else if ((strcmp(argv_function, "strlcpy") == 0) ||
		(strcmp(argv_function, "Strlcpy") == 0))
	{
		char	dest1[100] = "Never gonna let you down";
		char	dest2[100] = "Never gonna let you down";
		char	src[] = "Never gonna give you up";
		size_t	n = 15;
		size_t	real;
		size_t	mine;
		char	*argv_dest1;
		char	*argv_dest2;
		char	*argv_src;
		size_t	argv_n;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\n"
				" |2. String dest| \n |3. String src| \n"
				" |4. Int| \e[0m\n");
			return (0);
		}

		argv_dest1 = ft_strdup(argv[2]);
		argv_dest2 = ft_strdup(argv[2]);
		argv_src = ft_strdup(argv[3]);
		if (argv_dest1 == 0 || argv_dest2 == 0 || argv_src == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_dest1)
				free(argv_dest1);
			if (argv_dest2)
				free(argv_dest2);
			if (argv_src)
				free(argv_src);
			return (0);
		}
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_strlcpy.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("dest = %s\nsrc = %s\n|n = %zu|\n\n",
			argv_dest1, argv_src, argv_n);
		printf("Original:\t");
		real = strlcpy(argv_dest1, argv_src, argv_n);
		printf("\e[92m%zu\e[0m\n", real);
		printf("\t\t\e[92m%s\e[0m\n\n", argv_dest1);

		printf("My result:\t");
		mine = ft_strlcpy(argv_dest2, argv_src, argv_n);
		printf("\e[34m%zu\e[0m\n", mine);
		printf("\t\t\e[34m%s\e[0m\n\n", argv_dest2);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("dest = %s\nsrc = %s\n|n = %zu|\n\n", dest1, src, n);
		printf("Original:\t");
		real = strlcpy(dest1, src, n);
		printf("\e[92m%zu\e[0m\n", real);
		printf("\t\t\e[92m%s\e[0m\n\n", dest1);

		printf("My result:\t");
		mine = ft_strlcpy(dest2, src, n);
		printf("\e[34m%zu\e[0m\n", mine);
		printf("\t\t\e[34m%s\e[0m\n", dest2);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		free(argv_dest1);
		free(argv_dest2);
		free(argv_src);
		return (0);
	}
	else if ((strcmp(argv_function, "strlen") == 0) ||
		(strcmp(argv_function, "Strlen") == 0))
		{
		char	str[] = "Never gonna give you up, never gonna let you down";
		size_t	real;
		size_t	mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \e[0m\n");
			return (0);
		}
		char	*argv_str = argv[2];

		//FILE NAME
		printf("\n\e[1;7m ft_strlen.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n\n", argv_str);
		printf("Original:\t");
		real = strlen(argv_str);
		printf("\e[92m%zu\e[0m\n", real);

		printf("My result:\t");
		mine = ft_strlen(argv_str);
		printf("\e[34m%zu\e[0m\n\n", mine);
		printf("--------------------------------------------\n\n");

	//	//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n\n", str);
		printf("Original:\t");
		real = strlen(str);
		printf("\e[92m%zu\e[0m\n", real);

		printf("My result:\t");
		mine = ft_strlen(str);
		printf("\e[34m%zu\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strmapi") == 0) ||
		(strcmp(argv_function, "Strmapi") == 0))
	{
		char	str[] = "Never gonna give you up, never gonna let you down";
		char	*result;
		char	*argv_str;
		char	*argv_result;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \e[0m\n");
			return (0);
		}
		argv_str = argv[2];

		//FILE NAME
		printf("\n\e[1;7m ft_strmapi.c \e[0m\n\n");
			printf("\e[3m*Helper function transforms "
			"lowercase to uppercase.\e[0m\n");
		printf("--------------------------------------------\n\n");
		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n\n", argv_str);
		printf("My result:\n");
		argv_result = ft_strmapi(argv_str, helper_strmapi);
		if (argv_result)
			printf("\e[34m%s\e[0m\n\n", argv_result);
		else
			printf("\e[34m(null)\e[0m\n\n");
		free(argv_result);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n\n", str);
		printf("My result:\n");
		result = ft_strmapi(str, helper_strmapi);
		if (result)
			printf("\e[34m%s\e[0m\n", result);
		else
			printf("\e[34m(null)\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		free(result);
		return (0);
	}
	else if ((strcmp(argv_function, "strncmp") == 0) ||
		(strcmp(argv_function, "Strncmp") == 0))
	{
		char	str1[] = "Never gonna give you up,";
		char	str2[] = "Never gonna let you down";
		size_t	n = 15;
		int		real;
		int		mine;
		char	*argv_str1;
		char	*argv_str2;
		size_t	argv_n;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name|\e[0m\n"
				"\e[1;7m |2. String 1| \n |3. String 2| \n |4. Int| \e[0m\n");
			return (0);
		}

		argv_str1 = argv[2];
		argv_str2 = argv[3];
		argv_n = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_strncmp.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("s1 =\t%s\ns2 =\t%s\n|n = %zu|\n\n", argv_str1, argv_str2, argv_n);
		printf("Original:\t");
		real = strncmp(argv_str1, argv_str2, argv_n);
		printf("\e[92m%d\e[0m\n\n", real);

		printf("My result:\t");
		mine = ft_strncmp(argv_str1, argv_str2, argv_n);
		printf("\e[34m%d\e[0m\n\n", mine);
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("s1 =\t%s\ns2 =\t%s\n|n = %zu|\n\n", str1, str2, n);
		printf("Original:\t");
		real = strncmp(str1, str2, n);
		printf("\e[92m%d\e[0m\n\n", real);

		printf("My result:\t");
		mine = ft_strncmp(str1, str2, n);
		printf("\e[34m%d\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strnstr") == 0) ||
		(strcmp(argv_function, "Strnstr") == 0))
	{
		char	big[] =
			"Never gonna give you up, never gonna let you down";
		char	little[] = "let";
		size_t	len = 30;
		char	*real;
		char	*mine;
		size_t	argv_len;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \n"
				"\e[1;7m |2. String big| \n |3. String little| \n"
				"|4. Int| \e[0m\n");
			return (0);
		}
		char	*argv_big = argv[2];
		char	*argv_little = argv[3];
		argv_len = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_strnstr.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("Big string =\t%s\nLittle =\t%s\n|len = %zu|\n\n",
			argv_big, argv_little, argv_len);
		printf("Original:\t");
		real = strnstr(argv_big, argv_little, argv_len);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\t");
		mine = ft_strnstr(argv_big, argv_little, argv_len);
		if (mine)
			printf("\e[34m%s\e[0m\n\n", mine);
		else
			printf("\e[34m(null)\e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("Big string =\t%s\nLittle =\t%s\n|len = %zu|\n\n", big, little, len);

		printf("Original:\t");
		real = strnstr(big, little, len);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\t");
		mine = ft_strnstr(big, little, len);
		if (mine)
			printf("\e[34m%s\e[0m\n\n", mine);
		else
			printf("\e[34m(null)\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strrchr") == 0) ||
		(strcmp(argv_function, "Strrchr") == 0))
	{
		char	str[] = "Never gonna give you up, never gonna let you down";
		int		c = 'g';
		char	*argv_str;
		int		argv_c;
		char	*real;
		char	*mine;

		//ERROR CHECK
		if (argc < 4)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. String| \n |3. Character| \e[0m\n");
			return (0);
		}
		argv_str = argv[2];
		argv_c = argv[3][0];

		//FILE NAME
		printf("\n\e[1;7m ft_strrchr.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("%s\n|%c|\n\n", argv_str, argv_c);
		printf("Original:\t");
		real = strrchr(argv_str, argv_c);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\t");
		mine = ft_strrchr(argv_str, argv_c);
		if (mine)
			printf("\e[34m%s\e[0m\n\n", mine);
		else
			printf("\e[34m(null)\e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("%s\n|%c|\n\n", str, c);
		printf("Original:\t");
		real = strrchr(str, c);
		if (real)
			printf("\e[92m%s\e[0m\n\n", real);
		else
			printf("\e[92m(null)\e[0m\n\n");

		printf("My result:\t");
		mine = ft_strrchr(str, c);
		if (mine)
			printf("\e[34m%s\e[0m\n", mine);
		else
			printf("\e[34m(null)\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "strtrim") == 0) ||
		(strcmp(argv_function, "Strtrim") == 0))
	{
		char const	*s1 = "     Never gonna give you up, never gonna let   ";
		char const	*set = " ";
		char		*result;
		char		*argv_s1;
		char		*argv_set;
		char		*argv_result;

		//ERROR CHECK
		if (argc < 4)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 3x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name | \e[0m\n"
				"\e[1;7m |2. String s1| \n |3. String set| \e[0m\n");
			return (0);
		}
		argv_s1 = argv[2];
		argv_set = argv[3];

		//FILE NAME
		printf("\n\e[1;7m ft_strtrim.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("Trim = |%s|\n\n", argv_set);
		printf("Input:\t\t|%s|\n", argv_s1);
		printf("My result:\t");
		argv_result = ft_strtrim(argv_s1, argv_set);
		if (argv_result)
			printf("\e[34m|%s|\e[0m\n\n", argv_result);
		else
			printf("\e[34m(null)\e[0m\n\n");
		printf("--------------------------------------------\n\n");
		free(argv_result);

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("Trim = |%s|\n\n", set);
		printf("Input:\t\t|%s|\n", s1);
		printf("My result:\t");
		result = ft_strtrim(s1, set);
		if (result)
			printf("\e[34m|%s|\e[0m\n", result);
		else
			printf("\e[34m(null)\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		free(result);
		return (0);
	}
	else if ((strcmp(argv_function, "substr") == 0) ||
		(strcmp(argv_function, "Substr") == 0))
	{
		char const		s[] = "Never gonna give you up,";
		unsigned int	start = 7;
		size_t			len = 9;
		char			*result;
		char			*argv_s;
		char			*argv_result;
		unsigned int	argv_start;
		size_t			argv_len;

		//ERROR CHECK
		if (argc < 5)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 4x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \n \e[0m\n"
				"\e[1;7m |2. String| \n |3. Int start| \n |4. Int len| \e[0m\n");
			return (0);
		}
		argv_s = argv[2];
		argv_start = (unsigned int)ft_atoi(argv[3]);
		argv_len = (size_t)ft_atoi(argv[4]);

		//FILE NAME
		printf("\n\e[1;7m ft_substr.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: USING ARGV
		printf("Test 1: Using ARGV\n");
		printf("|start = %u| |len = %zu|\n\n", argv_start, argv_len);
		printf("Input:\t\t|%s|\n", argv_s);
		printf("My result:\t");
		argv_result = ft_substr(argv_s, argv_start, argv_len);
		if (argv_result)
		{
			printf("\e[34m|%s|\e[0m\n\n", argv_result);
			free(argv_result);
		}
		else
			printf("\e[34m(null)\e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 2: SIMPLE TEST
		printf("Test 2: Simple test\n");
		printf("|start = %u| |len = %zu|\n\n", start, len);
		printf("Input:\t\t|%s|\n", s);
		printf("My result:\t");
		result = ft_substr(s, start, len);
		if (result)
		{
			printf("\e[34m|%s|\e[0m\n", result);
			free(result);
		}
		else
			printf("\e[34m(null)\e[0m\n");
		printf("\n--------------------------------------------\n\n");

		//JOB DONE
		printf("\e[1;7m Job done! \e[0m\n");
		return (0);
	}
	else if ((strcmp(argv_function, "tolower") == 0) ||
		(strcmp(argv_function, "Tolower") == 0))
	{
		int		c1 = 'A';
		int		c2 = 'A';
		int		real;
		int		mine;
		char	*argv_real;
		char	*argv_mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need 2x ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character| \e[0m\n");
			return (0);
		}
		argv_real = strdup(argv[2]);
		argv_mine = strdup(argv[2]);
		if (argv_real == 0 || argv_mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_real)
				free(argv_real);
			if (argv_mine)
				free(argv_mine);
			return (0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_tolower.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("|%c|\n\n", argv_real[0]);
		real = tolower(argv_real[0]);
		mine = ft_tolower(argv_mine[0]);
		printf("Original:\t\e[92m%c\e[0m\n", real);
		printf("My result:\t\e[34m%c\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple test\n");
		printf("|%c|\n\n", c1);
		real = tolower(c1);
		mine = ft_tolower(c2);
		printf("Original:\t\e[92m%c\e[0m\n", real);
		printf("My result:\t\e[34m%c\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		free(argv_real);
		free(argv_mine);
		return (0);
	}
	else if ((strcmp(argv_function, "toupper") == 0) ||
		(strcmp(argv_function, "Toupper") == 0))
	{
		int		c1 = 'c';
		int		c2 = 'c';
		int		real;
		int		mine;
		char	*argv_real;
		char	*argv_mine;

		//ERROR CHECK
		if (argc < 3)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Need ARGV to work with! \e[0m\n"
				"\e[1;7m |1. Function name| \e[0m\n"
				"\e[1;7m |2. Character| \e[0m\n");
			return (0);
		}
		argv_real = strdup(argv[2]);
		argv_mine = strdup(argv[2]);
		if (argv_real == 0 || argv_mine == 0)
		{
			printf("\e[1;31;7m ERROR! \e[0m"
				"\e[1;7m Malloc bugged! \e[0m\n");
			if (argv_real)
				free(argv_real);
			if (argv_mine)
				free(argv_mine);
			return (0);
		}

		//FILE NAME
		printf("\n\e[1;7m ft_toupper.c \e[0m\n\n");
		printf("--------------------------------------------\n\n");

		//TEST 1: Using ARGV
		printf("Test 1: Using ARGV\n");
		printf("|%c|\n\n", argv_real[0]);
		real = toupper(argv_real[0]);
		mine = ft_toupper(argv_mine[0]);
		printf("Original:\t\e[92m%c\e[0m\n", real);
		printf("My result:\t\e[34m%c\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//TEST 2: Simple test
		printf("Test 2: Simple test\n");
		printf("|%c|\n\n", c1);
		real = toupper(c1);
		mine = ft_toupper(c2);
		printf("Original:\t\e[92m%c\e[0m\n", real);
		printf("My result:\t\e[34m%c\e[0m\n", mine);
		printf("\n--------------------------------------------\n\n");

		//JOB DONE!
		printf("\e[1;7m Job done! \e[0m\n");
		free(argv_real);
		free(argv_mine);
		return (0);
	}
}


