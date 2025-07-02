/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:05:55 by imane             #+#    #+#             */
/*   Updated: 2025/07/02 09:25:49 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void*   routine(void *arg)
{
    t_philo *philo;
    // static int i;
    philo = (t_philo *)arg;
    while(is_dead() == 0)
    {
        eating(philo);
        if(is_dead() == 1)
        break;
        sleeping(philo);     
        // if((*args_func())->must_eat_count > 0)
        // {
        //     if(i == (*args_func())->must_eat_count)
        //         break;
        //     else
        //         i++;
        // }
    }
    return(NULL);
}

void    update_last_meal(t_philo *philo)
{
    if(is_dead() == 0)
    {
        pthread_mutex_lock(&philo->last_meal_lock);
        philo->last_meal = get_current_time();
        pthread_mutex_unlock(&philo->last_meal_lock);
    }
}

void    eating(t_philo *philo)
{
    if(is_dead() == 1)
        return;
    if(is_dead() == 1)
        return;
    print_func(get_current_time(), philo->id, "is thiking");
    usleep(1000);
    if((&philo->next->fork) < (&philo->fork))
    {
        pthread_mutex_lock((&philo->next->fork));
        pthread_mutex_lock((&philo->fork));
    }
    else
    {
        pthread_mutex_lock((&philo->fork));
        pthread_mutex_lock((&philo->next->fork));
    }
    if(is_dead() == 0)
        print_func(get_current_time(), philo->id, "has taking a fork");
    if(is_dead() == 0)
        print_func(get_current_time(), philo->id, "is eating");
    if(is_dead() == 0)
        usleep((*args_func())->time_to_eat * 1000);
    update_last_meal(philo);
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(&philo->next->fork);
}

void    sleeping(t_philo *philo)
{
    t_args *args;

    args = *args_func();
    print_func(get_current_time(), philo->id, "is sleeping");
    if(is_dead() == 1)
        return;
    usleep(args->time_to_sleep * 1000);
    if(is_dead() == 1)
        return;
}
