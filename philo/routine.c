/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:05:55 by imane             #+#    #+#             */
/*   Updated: 2025/07/04 21:50:54 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	must_eat_case(t_philo *philo)
{
	int	eat;
	int	total_meals;

	eat = (*args_func())->must_eat_count;
	total_meals = (*args_func())->philo_count * (*args_func())->must_eat_count;
	while (stop_simulation() == 0)
	{
		if (stop_simulation())
			break ;
		eating(philo);
		inc_meals_eaten();
		if (stop_simulation())
			break ;
		sleeping(philo);
		if (stop_simulation())
			break ;
		usleep(50);
		if (stop_simulation())
			break ;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	if ((*args_func())->must_eat_count >= 0)
		must_eat_case(philo);
	else
	{
		while (is_dead() == 0)
		{
			eating(philo);
			if (is_dead() == 1)
				break ;
			sleeping(philo);
			usleep(100);
		}
		return (NULL);
	}
	return (NULL);
}

void	mutex_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2, int flag)
{
	if (flag == 1)
	{
		pthread_mutex_lock(fork1);
		pthread_mutex_lock(fork2);
	}
	if (flag == 2)
	{
		pthread_mutex_unlock(fork1);
		pthread_mutex_unlock(fork2);
	}
}

void	eating(t_philo *philo)
{
	if (stop_simulation())
		return ;
	print_func(philo->id, "is thiking");
	if (stop_simulation())
		return ;
	if (philo->id % 2 != 0)
	{
		usleep(500);
		mutex_forks(&philo->next->fork, &philo->fork, 1);
	}
	else
		mutex_forks(&philo->fork, &philo->next->fork, 1);
	if (stop_simulation() == 0)
		print_func(philo->id, "has taking a fork");
	if (stop_simulation() == 0)
		print_func(philo->id, "is eating");
	if (stop_simulation() == 0)
	{
		update_last_meal(philo);
		ft_sleep((*args_func())->time_to_eat);
	}
	mutex_forks(&philo->fork, &philo->next->fork, 2);
}

void	sleeping(t_philo *philo)
{
	if (stop_simulation())
		return ;
	print_func(philo->id, "is sleeping");
	if (stop_simulation())
		return ;
	ft_sleep((*args_func())->time_to_sleep);
	if (stop_simulation())
		return ;
}
