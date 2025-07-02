/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:05:55 by imane             #+#    #+#             */
/*   Updated: 2025/07/02 22:28:39 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	must_eat_case(t_philo *philo)
{
	int	i;
	int	eat;

	i = 0;
	eat = (*args_func())->must_eat_count;
	while (i < eat)
	{
		eating(philo);
		sleeping(philo);
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;
	int		eat;

	i = 0;
	philo = (t_philo *)arg;
	if ((*args_func())->must_eat_count >= 0)
	{
		eat = (*args_func())->must_eat_count;
		must_eat_case(philo);
	}
	else
	{
		while (is_dead() == 0)
		{
			eating(philo);
			if (is_dead() == 1)
				break ;
			sleeping(philo);
		}
		return (NULL);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	if (is_dead() == 1)
		return ;
	print_func(philo->id, "is thiking");
	if (philo->id % 2 != 0)
	{
		usleep(500);
		pthread_mutex_lock((&philo->next->fork));
		pthread_mutex_lock((&philo->fork));
	}
	else
	{
		pthread_mutex_lock((&philo->fork));
		pthread_mutex_lock((&philo->next->fork));
	}
	if (is_dead() == 0)
		print_func(philo->id, "has taking a fork");
	if (is_dead() == 0)
		print_func(philo->id, "is eating");
	if (is_dead() == 0)
	{
		update_last_meal(philo);
		usleep((*args_func())->time_to_eat * 1000);
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	sleeping(t_philo *philo)
{
	t_args	*args;

	args = *args_func();
	print_func(philo->id, "is sleeping");
	if (is_dead() == 1)
		return ;
	usleep(args->time_to_sleep * 1000);
	if (is_dead() == 1)
		return ;
}
