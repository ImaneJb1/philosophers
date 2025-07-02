/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:54 by imane             #+#    #+#             */
/*   Updated: 2025/07/02 12:45:06 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    set_death(void)
{
    pthread_mutex_lock(&(*args_func())->death_lock);
    *death() = 1;
    pthread_mutex_unlock(&(*args_func())->death_lock);
}

void    *is_someone_died(void *arg)
{
    t_philo *list;
    
    (void)arg;
    list = *philo_list();
    while(list)
    {
        if(get_current_time() - list->last_meal > (*args_func())->time_to_die)
        {
            set_death();
            print_func (list->id, "has died");
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

    if(argc < 5 || argc >= 6)
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
