/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:46:01 by osukhore          #+#    #+#             */
/*   Updated: 2025/12/05 12:34:47 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

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

static void	style(char style)
{
	if (style == 'B')
		printf("\e[34m");
	else if (style == 'E')
		printf("\e[1;31;7m");
	else if (style == 'T')
		printf("\e[1;7m");
	else if (style == 'R')
		printf("\e[0m");
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*linetest;
	int		i;
	int		argv_n;

	// ERROR CHECK
	if (argc < 3)
	{
		printf("\n--------------------------------------------\n");
		style('E');
		printf(" ERROR ");
		style('R');
		style('T');
		printf(" Need ARGV to work with: \n\n"
				" 1. File path \n"
				" 2. Lines to read \n");
		style('R');
		printf("--------------------------------------------\n");
		return (0);
	}

	argv_n = ft_atoi(argv[2]);

	// FILE NAME
	style('T');
	printf(" FILE: %s ", argv[1]);
	style('R');

	// TEST: READ FIRST N LINES
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST: FIRST %d LINES \n", argv_n);
	style('R');
	printf("\n");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		style('E');
		printf("Could not open file\n");
		style('R');
		return (0);
	}

	i = 0;
	while (i < argv_n)
	{
		linetest = get_next_line(fd);
		if (!linetest)
			printf("\n");
		printf("%d: %s", (i + 1), linetest);
		free(linetest);
		i++;
	}
	printf("\n\nRead %d lines\n\n", i);

	close(fd);

	printf("--------------------------------------------\n");

	return (0);
}
