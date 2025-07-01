/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:48:08 by imane             #+#    #+#             */
/*   Updated: 2025/07/01 17:17:06 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int    is_dead(void)
{
    int tmp;

    pthread_mutex_lock(&(*args_func())->death_lock);
    tmp = *death();
    pthread_mutex_unlock(&(*args_func())->death_lock);
    return(tmp);
}

void    ft_sleep(long sleep_time)
{
    while(sleep_time > 0)
    {
        if(*death() == 1)
            return;
        usleep(100);
        sleep_time = sleep_time - 100;
    }
}

void am_i_dead(t_philo *philo)
{
    t_args  *args;

    args = *args_func();
    if((get_current_time() - philo->last_meal) >= args->time_to_die)
    {
        printf("%ld\n", get_current_time() - philo->last_meal);
        philo->death = 1;
    }
}
