/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globales.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:20:25 by imane             #+#    #+#             */
/*   Updated: 2025/07/01 12:22:18 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo **philo_list(void)
{
    static t_philo *list;
    return(&list);
}

t_args    **args_func(void)
{
    static t_args *args;
    return(&args);
}

int *death(void)
{
    static int death;
    return(&death);
}