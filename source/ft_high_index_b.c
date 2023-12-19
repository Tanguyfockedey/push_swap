/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_high_index_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:31:48 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/19 17:58:18 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_high_index_b(t_stacks *stacks)
{
	int	i;
	int	high_index;
	int	high_nb;

	high_nb = 0;
	i = 1;
	while (i <= stacks->size_b)
	{
		if (ft_clst_value(*stacks->b, i) > high_nb)
		{
			high_nb = ft_clst_value(*stacks->b, i);
			high_index = i;
		}
		i++;
	}
	return (high_index);
}
