/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globales.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:20:25 by imane             #+#    #+#             */
/*   Updated: 2025/07/04 21:50:42 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	**philo_list(void)
{
	static t_philo	*list;

	return (&list);
}

t_args	**args_func(void)
{
	static t_args	*args;

	return (&args);
}

int	*death(void)
{
	static int	death;

	return (&death);
}

int	*meals_eaten(void)
{
	static int	meals;

	return (&meals);
}
