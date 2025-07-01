/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:19:03 by ijoubair          #+#    #+#             */
/*   Updated: 2025/07/01 17:23:20 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_func(long time, int id, char *str)
{
	pthread_mutex_lock(&(*args_func())->write_lock);
    printf("%ld %d %s\n",time, id, str);
	pthread_mutex_unlock(&(*args_func())->write_lock);
}
