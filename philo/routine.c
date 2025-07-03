/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:05:55 by imane             #+#    #+#             */
/*   Updated: 2025/07/03 17:44:04 by ijoubair         ###   ########.fr       */
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
	if (is_dead() == 1)
		return ;
	print_func(philo->id, "is thiking");
	if (is_dead() == 1)
		return ;
	if (philo->id % 2 != 0)
	{
		usleep(500);
		mutex_forks(&philo->next->fork, &philo->fork, 1);
	}
	else
		mutex_forks(&philo->fork, &philo->next->fork, 1);
	if (is_dead() == 0)
		print_func(philo->id, "has taking a fork");
	if (is_dead() == 0)
		print_func(philo->id, "is eating");
	if (is_dead() == 0)
	{
		update_last_meal(philo);
		ft_sleep((*args_func())->time_to_eat);
	}
	mutex_forks(&philo->fork, &philo->next->fork, 2);
}

void	sleeping(t_philo *philo)
{
	print_func(philo->id, "is sleeping");
	if (is_dead() == 1)
		return ;
	ft_sleep((*args_func())->time_to_sleep);
	if (is_dead() == 1)
		return ;
}
