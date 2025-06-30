/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:41:10 by imane             #+#    #+#             */
/*   Updated: 2025/06/29 09:51:24 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copilot: disable
#include "../philosopher.h"

void    new_node(t_philo *node)
{
    t_philo **list;
    t_philo *temp;

    list = philo_list();
    if (*list == NULL)
    {
        *list = node;
        node->next = node;
        return;
    }
    temp = *list;
    while (temp->next != *list)
        temp = temp->next;
    temp->next = node;
    node->next = *list;    
}

