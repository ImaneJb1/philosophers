/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:54 by imane             #+#    #+#             */
/*   Updated: 2025/07/01 13:49:32 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    *is_someone_died(void *arg)
{
    t_philo *list;

    (void)arg;
    list = *philo_list();
    while(list)
    {
        if(list->death == 1)
        {
            *death() = 1;
            printf("%d has died\n", list->id);
            break;
        }
        list = list->next;
    }
    return(NULL);
}

void    moniteur(void)
{
    pthread_t   thread;
    
    pthread_create(&thread, NULL, is_someone_died, NULL);
    pthread_join(thread, NULL);
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
        if (philos->next == head)
            pthread_create((&philos->thread), NULL, routine, philos);
    }
    moniteur();
    philos = head;
    while(philos->next != head)
    {
        pthread_join(philos->thread, NULL); // waiting for each thread to finish
        philos = philos->next;
        if (philos->next == head)
            pthread_join(philos->thread, NULL); // waiting for each thread to finish
    }
    return 0;
}
