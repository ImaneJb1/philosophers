/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:54 by imane             #+#    #+#             */
/*   Updated: 2025/07/04 20:00:20 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	done_eating(int total_meals)
{
	pthread_mutex_lock(&(*args_func())->done_eating_lock);
	if(get_meals_eaten() >= total_meals)
	{
		pthread_mutex_unlock(&(*args_func())->done_eating_lock);
		return (1);
	}
	pthread_mutex_unlock(&(*args_func())->done_eating_lock);
	return 0;
}

int	stop_simulation(void)
{
	int total_meals;

	total_meals = (*args_func())->philo_count * (*args_func())->must_eat_count;
	if(is_dead())
		return (1);
	// printf("meals eaten =%d total meals=%d\n", get_meals_eaten(), total_meals);
	if(done_eating(total_meals))
		return (2);
	return(0);
}

void	waiting_threads(t_philo *head)
{
	t_philo	*philos;

	philos = head;
	while (philos->next != head)
	{
		pthread_join(philos->thread, NULL);
		philos = philos->next;
		if (philos->next == head)
			pthread_join(philos->thread, NULL);
	}
}

void	inc_meals_eaten(void)
{
	pthread_mutex_lock(&(*args_func())->meals_eaten_lock);
	*meals_eaten() += 1;
	pthread_mutex_unlock(&(*args_func())->meals_eaten_lock);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_philo	*head;

	if (parsing(argc, argv) < 0)
		return (1);
	fill_list(argv);
	head = *philo_list();
	philos = head;
	(*args_func())->start_time = start_time();
	while (philos->next != head)
	{
		pthread_create((&philos->thread), NULL, routine, philos);
		philos = philos->next;
		if (philos->next == head)
			pthread_create((&philos->thread), NULL, routine, philos);
	}
	mentor();
	waiting_threads(philos);
	destroy_mutex_lock();
	return (0);
}
