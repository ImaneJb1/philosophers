/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:54 by imane             #+#    #+#             */
/*   Updated: 2025/06/29 22:14:55 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    *printsmth(void *arg)
{
    (void)arg;
    printf("this is a thread\n");
    return(NULL);
}


 int main(int argc, char **argv)
{
    
    t_philo *philos;

    if(argc < 5)
        return 0;
    printf("A\n");
    init_args(argv);
    printf("B\n");
    fill_list(argv);
    philos = *philo_list();
    while(philos)
    {
        printf("loop\n");
        pthread_create((&philos->thread), NULL, routine, philos);
        pthread_join(philos->thread, NULL);
        philos = philos->next;
    }
    return 0;
}
