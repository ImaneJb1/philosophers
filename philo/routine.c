/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:05:55 by imane             #+#    #+#             */
/*   Updated: 2025/06/29 11:34:40 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void*   routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    eating(philo);
    return(NULL);
}

void    eating(t_philo *philo)
{
    pthread_mutex_lock((&philo->fork));
    pthread_mutex_lock((&philo->next->fork));
    printf("%d is eating\n", philo->id);
    usleep(philo->eat_count);
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(&philo->fork);
}
// void    sleeping(void)
// {
//     t_args *args;

//     args = args_func();
//     usleep(args->time_to_sleep);
// }

// void    thinking(void)
// {
//      t_args *args;

//     args = args_func();
//     usleep(args->);
// }