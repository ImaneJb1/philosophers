/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_the_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:05:00 by imane             #+#    #+#             */
/*   Updated: 2025/06/30 18:23:02 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo **philo_list(void)
{
    static t_philo *list;
    return(&list);
}

void    fill_list(char **argv)
{
    t_philo *node;
    t_args *args;
    int i;
    
    init_args(argv);
    args = *args_func(); // args is null
    i = 0;
    while(i < args->philo_count)
    {
        node = malloc(sizeof(t_philo));
        if(!node)
            return;
        node->id = i + 1;
        node->eat_count = 0;
        pthread_mutex_init(&node->fork, NULL);
        new_node(node);
        i++;
    }
    
}