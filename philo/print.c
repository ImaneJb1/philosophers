/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:19:03 by ijoubair          #+#    #+#             */
/*   Updated: 2025/07/02 14:44:05 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_func(int id, char *str)
{
	pthread_mutex_lock(&(*args_func())->write_lock);
	printf("%ld %d %s\n", get_current_time(), id, str);
	pthread_mutex_unlock(&(*args_func())->write_lock);
}
