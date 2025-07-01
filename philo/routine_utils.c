/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:48:08 by imane             #+#    #+#             */
/*   Updated: 2025/07/01 13:42:35 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    ft_sleep(long sleep_time)
{
    while(sleep_time > 0)
    {
        if(*death() == 1)
            return;
        usleep(100);
        sleep_time -= 100;
    }
}

void am_i_dead(t_philo *philo)
{
    t_args  *args;

    args = *args_func();
    if((get_current_time() - philo->last_meal) > args->time_to_die)
        philo->death = 1;
}
