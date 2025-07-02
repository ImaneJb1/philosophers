/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:29:10 by ijoubair          #+#    #+#             */
/*   Updated: 2025/07/02 14:44:33 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 5)
		return (-1);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			write(2, "Error Positive numbers are required\n", 38);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	parsing(int argc, char **argv)
{
	if (check_args(argc, argv) < 0)
		exit(0);
}
