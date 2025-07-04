/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:51:46 by ijoubair          #+#    #+#             */
/*   Updated: 2025/07/04 20:03:40 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_meals_eaten()
{
	int tmp;

	pthread_mutex_lock(&(*args_func())->meals_eaten_lock);
	tmp = *meals_eaten();
	pthread_mutex_unlock(&(*args_func())->meals_eaten_lock);
	return(tmp);
}


void	set_death(void)
{
	pthread_mutex_lock(&(*args_func())->death_lock);
	*death() = 1;
	pthread_mutex_unlock(&(*args_func())->death_lock);
}

void	*is_someone_died(void *arg)
{
	t_philo	*list;

	(void)arg;

	list = *philo_list();
	while (list)
	{
		if(stop_simulation())
		break;
		if (get_current_time()
		- get_last_meal(list) > (*args_func())->time_to_die)
		{
			set_death();
			print_func(list->id, "has died");
			break ;
		}
		usleep(100);
		list = list->next;
	}
	return (NULL);
}

void	mentor(void)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, is_someone_died, NULL);
	pthread_join(thread, NULL);
}
