/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:48:08 by imane             #+#    #+#             */
/*   Updated: 2025/07/03 17:45:04 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_dead(void)
{
	int	tmp;

	pthread_mutex_lock(&(*args_func())->death_lock);
	tmp = *death();
	pthread_mutex_unlock(&(*args_func())->death_lock);
	return (tmp);
}

void	ft_sleep(long time)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < time)
	{
		if (*death() == 1)
			return ;
		usleep(100);
	}
}

void	am_i_dead(t_philo *philo)
{
	t_args	*args;

	args = *args_func();
	if ((get_current_time() - philo->last_meal) >= args->time_to_die)
	{
		printf("%ld\n", get_current_time() - philo->last_meal);
		philo->death = 1;
	}
}

void	update_last_meal(t_philo *philo)
{
	if (is_dead() == 0)
	{
		pthread_mutex_lock(&philo->last_meal_lock);
		philo->last_meal = get_current_time();
		pthread_mutex_unlock(&philo->last_meal_lock);
	}
}

int	get_last_meal(t_philo *philo)
{
	long	tmp;

	pthread_mutex_lock(&philo->last_meal_lock);
	tmp = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_lock);
	return (tmp);
}
