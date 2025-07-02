/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:54 by imane             #+#    #+#             */
/*   Updated: 2025/07/02 21:44:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_philo	*head;

	if(parsing(argc, argv) < 0)
		return(1);
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
