/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:54 by imane             #+#    #+#             */
/*   Updated: 2025/06/30 19:31:51 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    *printsmth(void *arg)
{
    (void)arg;
    printf("this is a thread\n");
    return(NULL);
}
void    ft_sleep(long sleep_time)
{
    while(sleep_time > 0)
    {
        usleep(100);
        sleep_time -= 100;
    }
}

 int main(int argc, char **argv)
{
    
    t_philo *philos;
    t_philo *head;

    if(argc < 5)
        return 0;
    init_args(argv);
    fill_list(argv);
    head = *philo_list();
    philos = head;
    (*args_func())->start_time = start_time();
    while(philos->next != head)
    {
        pthread_create((&philos->thread), NULL, routine, philos);
        philos = philos->next;
    }
    philos = head;
    while(philos->next != head)
    {
        pthread_join(philos->thread, NULL);
        philos = philos->next;
    }
    return 0;
}
