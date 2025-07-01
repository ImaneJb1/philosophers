/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:05:55 by imane             #+#    #+#             */
/*   Updated: 2025/07/01 13:52:17 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void*   routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    while(*death() == 0)
    {
        eating(philo);
        sleeping(philo);
    }
    return(NULL);
}

void    eating(t_philo *philo)
{
    t_args *args;
    
    args = *args_func();
    if(get_current_time() > args->time_to_die)
        philo->death = 1;
    printf("%ld %d is thinking\n",get_current_time(), philo->id);
    pthread_mutex_lock((&philo->fork));
    pthread_mutex_lock((&philo->next->fork));
    printf("%ld %d has taking a fork\n", get_current_time(),philo->id);
    printf("%ld %d is eating\n", get_current_time(), philo->id);
    ft_sleep((*args_func())->time_to_eat * 1000);
    philo->last_meal = get_current_time();
    am_i_dead(philo);
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(&philo->next->fork);
}

void    sleeping(t_philo *philo)
{
    t_args *args;

    args = *args_func();
    printf("%ld %d is sleeping\n", get_current_time(), philo->id);
    ft_sleep(args->time_to_sleep * 1000);
}
