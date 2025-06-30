/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:19:01 by imane             #+#    #+#             */
/*   Updated: 2025/06/30 13:25:27 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_args    **args_func(void)
{
    static t_args *args;
    return(&args);
}

void    init_args(char **argv)
{
    t_args  **args;
    
    args = args_func();
    *args = malloc(sizeof(t_args));
    if(args == NULL)
        return;
    (*args)->philo_count = ft_atoi(argv[1]);
    (*args)->time_to_die = ft_atoi(argv[2]);
    (*args)->time_to_eat = ft_atoi(argv[3]);
    (*args)->time_to_sleep = ft_atoi(argv[4]);
    if(argv[5])
        (*args)->must_eat_count = ft_atoi(argv[5]);
    else
        (*args)->must_eat_count = -1;
    
}
