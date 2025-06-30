/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:17:16 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/30 19:16:36 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


long	start_time(void)
{
	struct timeval tv;
	long	time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return(time_ms);
}
long	get_current_time(void)
{
	struct timeval tv;
	long	time_ms;
	long	current;
	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	current = time_ms - (*args_func())->start_time;
	return(current);
}
