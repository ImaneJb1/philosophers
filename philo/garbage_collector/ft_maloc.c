/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:26:39 by ijoubair          #+#    #+#             */
/*   Updated: 2025/07/02 22:16:35 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	**block_mem(void)
{
	static void	*memo;
	return(&memo);
}
void	allocate_block_mem()
{
	*block_mem() = malloc(100000);
}
void	*ft_malloc(size_t size)
{
	static int	offset;
	// void		*memo;
	void		*block;

	if(*block_mem() == NULL)
		allocate_block_mem();
	block = *block_mem();
	block = block + offset;
	offset += size;
	return(block);	
}

void	ft_free_all(void)
{
	free(*block_mem());
}

