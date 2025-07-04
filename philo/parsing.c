/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:29:10 by ijoubair          #+#    #+#             */
/*   Updated: 2025/07/04 21:50:33 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	is_num(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (-1);
	while (argv[i])
	{
		if (!is_num(argv[i]))
		{
			write(2, "Syntax error\n", 12);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (check_args(argc, argv) < 0 || ft_atoi(argv[1]) == 0)
		return (-1);
	return (0);
}
