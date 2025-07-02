/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_the_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:05:00 by imane             #+#    #+#             */
/*   Updated: 2025/07/02 22:21:29 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_mutex_lock(void)
{
	t_args	*args;
	t_philo	*philo;
	t_philo	*tmp;
	int		i;

	i = 0;
	args = *args_func();
	philo = *philo_list();
	pthread_mutex_destroy(&args->death_lock);
	pthread_mutex_destroy(&args->write_lock);
	while (i < args->philo_count)
	{
		pthread_mutex_destroy(&philo->fork);
		pthread_mutex_destroy(&philo->current_time);
		pthread_mutex_destroy(&philo->last_meal_lock);
		tmp = philo->next;
		philo = tmp;
		i++;
	}
	ft_free_all();
}

void	fill_list(char **argv)
{
	int		i;
	t_philo	*node;
	t_args	*args;

	init_args(argv);
	args = *args_func();
	i = 0;
	while (i < args->philo_count)
	{
		node = ft_malloc(sizeof(t_philo));
		if (!node)
			return ;
		node->id = i + 1;
		node->eat_count = 0;
		node->death = 0;
		node->last_meal = 0;
		pthread_mutex_init(&node->fork, NULL);
		pthread_mutex_init(&node->current_time, NULL);
		pthread_mutex_init(&node->last_meal_lock, NULL);
		new_node(node);
		i++;
	}
}
