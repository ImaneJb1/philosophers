/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_the_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:05:00 by imane             #+#    #+#             */
/*   Updated: 2025/06/30 11:54:59 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo **philo_list(void)
{
    static t_philo *list;
    return(&list);
}

// void    fill_list(void)
// {
//     t_philo *node;
//     t_philo **list;
//     int i;

//     list = philo_list();
//     i = 0;
//     while (i < args_func()->philo_count)
//     {
//         node = malloc(sizeof(t_philo));
//         if (!node)
//             return; // Handle memory allocation failure
//         node->id = i + 1;
//         node->eat_count = 0;
//         node->last_meal = 0;
//         node->args = args_func();
//         node->fork = &args_func()->forks[i];
//         new_node(node);
//         i++;
//     }
// }

void    fill_list(char **argv)
{
    t_philo *node;
    t_args *args;
    int i;
    
    init_args(argv);
    args = *args_func(); // args is null
    if(args == NULL)
        printf("ikhan\n");
    printf("%d philo\n", args->philo_count);
    i = 0;
    while(i < args->philo_count)
    {
        printf("%d filling list\n", args->philo_count);
        node = malloc(sizeof(t_philo));
        if(!node)
            return;
        node->id = i + 1;
        node->eat_count = 0;
        new_node(node);
        i++;
    }
    
}